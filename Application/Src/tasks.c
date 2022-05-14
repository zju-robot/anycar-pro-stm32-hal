#define TX_BUF_SIZE 80

#include "tasks.h"

#include "stm32f3xx_hal.h"

#include "common/mavlink.h"
#include "mavlink_helpers.h"

#include "anycar_pro.h"

/**
 * @brief 默认任务, 用于启动和调试
 *
 * @param argument FreeRTOS默认参数. 可无视
 */
void StartDefaultTask(void *argument)
{
  UNUSED(argument);

  osTimerStart(sendHeartbeatsTimerHandle, 1000);

  for (;;)
  {
    osDelay(1);
  }
}

/**
 * @brief 消息解析与推送任务
 *
 * @param argument FreeRTOS默认参数. 可无视
 */
void StartParseMessagesTask(void *argument)
{
  UNUSED(argument);

  uint8_t byte;
  mavlink_message_t mavMsg;
  mavlink_status_t mavStatus;
  GenericMsg genericMsg;

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
        mavlink_msg_heartbeat_decode(&mavMsg, &genericMsg.heartbeat);
        genericMsg.msgid = MAVLINK_MSG_ID_HEARTBEAT;
        osMessageQueuePut(heartbeatsQueueHandle, &genericMsg.heartbeat, 0, 0);
        // osMessageQueuePut(transmitMessagesQueueHandle, &genericMsg, 0, 0);
        break;

      case MAVLINK_MSG_ID_SET_POSITION_TARGET_LOCAL_NED:
        mavlink_msg_set_position_target_local_ned_decode(&mavMsg,
                                                         &genericMsg.command);
        genericMsg.msgid = MAVLINK_MSG_ID_SET_POSITION_TARGET_LOCAL_NED;
        osMessageQueuePut(commandsQueueHandle, &genericMsg.command, 0, 0);
        // osMessageQueuePut(transmitMessagesQueueHandle, &genericMsg, 0, 0);
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

  uint8_t buffer[TX_BUF_SIZE];
  mavlink_message_t mavMsg;
  GenericMsg genericMsg;

  for (;;)
  {
    // 等待新的待发送消息
    osMessageQueueGet(transmitMessagesQueueHandle, &genericMsg, NULL,
                      osWaitForever);

    // 根据消息类型进行相应的编码
    switch (genericMsg.msgid)
    {
    case MAVLINK_MSG_ID_HEARTBEAT:
      mavlink_msg_heartbeat_encode(0, 0, &mavMsg, &genericMsg.heartbeat);
      break;

    case MAVLINK_MSG_ID_SET_POSITION_TARGET_LOCAL_NED:
      mavlink_msg_set_position_target_local_ned_encode(0, 0, &mavMsg,
                                                       &genericMsg.command);
      break;

    default:
      continue;
      ;
    }

    // 等待当前串口占用解除
    osSemaphoreAcquire(usbOccupationBinarySemHandle, osWaitForever);

    // 发送消息
    uint16_t length = mavlink_msg_to_send_buffer(buffer, &mavMsg);
    HAL_UART_Transmit_DMA(&USB_HUART, buffer, length);
  }
}

/**
 * @brief 定时循环发送心跳包的回调
 *
 * @param argument FreeRTOS默认参数. 可无视
 */
void SendHeartbeatsCallback(void *argument)
{
  static GenericMsg genericMsg = {.msgid = MAVLINK_MSG_ID_HEARTBEAT};
  osMessageQueuePut(transmitMessagesQueueHandle, &genericMsg, 0, 0);
}
