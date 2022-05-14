#include "connection.h"

#include "tasks.h"
#include "communication.h"

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

void StartConnection() { osTimerStart(sendHeartbeatsTimerHandle, 1000); }
