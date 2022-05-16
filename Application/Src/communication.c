#include "communication.h"

#include "anycar_pro.h"
#include "tasks.h"

static uint8_t receivedByte;

void Uart_RxCpltCallback(UART_HandleTypeDef *huart)
{
  UNUSED(huart);

  HAL_UART_Receive_IT(&EXT_HUART, &receivedByte, 1); //开启下一次接收
  osMessageQueuePut(receivedBytesQueueHandle, &receivedByte, 0,
                    0); //压入本次收到的字节
}

void Uart_TxCpltCallback(UART_HandleTypeDef *huart) { UNUSED(huart); }

/**
 * @brief 消息解析与推送任务
 *
 * @param argument FreeRTOS默认参数. 可无视
 */
void StartParseMessagesTask(void *argument)
{
  UNUSED(argument);

  static uint8_t byte;
  static mavlink_message_t mavMsg;
  static mavlink_status_t mavStatus;
  static mavlink_heartbeat_t heartbeatMsg;
  static GenericCmd cmdMsg;

  for (;;)
  {
    // 从字节流接收队列中读取一个字节
    osMessageQueueGet(receivedBytesQueueHandle, &byte, NULL, osWaitForever);

    // 调用MavLink的API解析字节
    if (mavlink_parse_char(0, byte, &mavMsg, &mavStatus))
    {
      // 根据消息类型进行相应解码和标注以及推送
      switch (mavMsg.msgid)
      {
      case MAVLINK_MSG_ID_HEARTBEAT:
        mavlink_msg_heartbeat_decode(&mavMsg, &heartbeatMsg);
        osMessageQueuePut(heartbeatsQueueHandle, &heartbeatMsg, 0, 0);
        break;

      case MAVLINK_MSG_ID_SET_SPEED:
        cmdMsg.msgid = MAVLINK_MSG_ID_SET_SPEED;
        mavlink_msg_set_speed_decode(&mavMsg, &cmdMsg.setSpeed);
        osMessageQueuePut(commandsQueueHandle, &cmdMsg, 0, 0);
        break;

      case MAVLINK_MSG_ID_SET_MOTORS_RATE:
        cmdMsg.msgid = MAVLINK_MSG_ID_SET_MOTORS_RATE;
        mavlink_msg_set_motors_rate_decode(&mavMsg, &cmdMsg.setMotorsRate);
        osMessageQueuePut(commandsQueueHandle, &cmdMsg, 0, 0);
        break;

      case MAVLINK_MSG_ID_SET_ODOMETRY:
        cmdMsg.msgid = MAVLINK_MSG_ID_SET_ODOMETRY;
        mavlink_msg_set_odometry_decode(&mavMsg, &cmdMsg.setOdometry);
        osMessageQueuePut(commandsQueueHandle, &cmdMsg, 0, 0);
        break;

      default:
        continue;
      }
    }
  }
}

/**
 * @brief 消息编码与发送任务
 *
 * @param argument FreeRTOS默认参数. 可无视
 */
void StartTransmitMessagesTask(void *argument)
{
  UNUSED(argument);

  static uint8_t buffer[TX_BUF_SIZE];
  static mavlink_message_t mavMsg;
  static GenericTxMsg genericTxMsg;

  for (;;)
  {
    // 等待新的待发送消息
    osMessageQueueGet(transmitMessagesQueueHandle, &genericTxMsg, NULL,
                      osWaitForever);

    // 根据消息类型进行相应的编码
    switch (genericTxMsg.msgid)
    {
    case MAVLINK_MSG_ID_HEARTBEAT:
      mavlink_msg_heartbeat_encode(0, 0, &mavMsg, &genericTxMsg.heartbeat);
      break;

    case MAVLINK_MSG_ID_MOTION_STATE:
      mavlink_msg_motion_state_encode(0, 0, &mavMsg, &genericTxMsg.motionState);
      break;

    default:
      continue;
      ;
    }

    // 发送消息
    uint16_t length = mavlink_msg_to_send_buffer(buffer, &mavMsg);
    while (HAL_UART_Transmit_IT(&EXT_HUART, buffer, length) != HAL_OK)
      osDelay(1);
  }
}

void StartCommunication()
{
  // USB串口初始化
  EXT_HUART.RxCpltCallback = Uart_RxCpltCallback;
  EXT_HUART.TxCpltCallback = Uart_TxCpltCallback;
  HAL_UART_Receive_IT(&EXT_HUART, &receivedByte, 1);

  osMessageQueueReset(receivedBytesQueueHandle);
  osThreadResume(parseMessagesTaskHandle);
  osThreadResume(transmitMessagesTaskHandle);
}

void StopCommunication()
{
  osThreadSuspend(parseMessagesTaskHandle);
  osThreadSuspend(transmitMessagesTaskHandle);
  EXT_HUART.RxCpltCallback = NULL;
  EXT_HUART.TxCpltCallback = NULL;
}
