#include "connection.h"

#include "tasks.h"
#include "communication.h"
#include "motion_control.h"

/**
 * @brief 定时循环发送心跳包的回调
 *
 * @param argument FreeRTOS默认参数. 可无视
 */
void SendHeartbeatsCallback(void *argument)
{
  static GenericTxMsg genericTxMsg = {.msgid = MAVLINK_MSG_ID_HEARTBEAT};
  osMessageQueuePut(transmitMessagesQueueHandle, &genericTxMsg, 0, 0);
}

/**
 * @brief 检查串口是否连接上. 如果断连立刻停止电机
 *
 * @param argument FreeRTOS默认参数. 可无视
 */
void StartCheckConnectionTask(void *argument)
{
  static mavlink_heartbeat_t heartbeatMsg;
  static uint32_t connected = 0;

  for (;;)
  {
    osStatus_t status = osMessageQueueGet(heartbeatsQueueHandle, &heartbeatMsg,
                                          0, HEARTBEAT_TIMEOUT);

    if (status == osOK && !connected)
      StartMotionControl(), connected = 1;
    else if (status != osOK && connected)
      StopMotionControl(), connected = 0;
  }
}

void StartConnection()
{
  osTimerStart(sendHeartbeatsTimerHandle, HEARTBEAT_PERIOD);
  osThreadResume(checkConnectionTaskHandle);
}

void StopConnection()
{
  osThreadSuspend(checkConnectionTaskHandle);
  osTimerStop(sendHeartbeatsTimerHandle);
}
