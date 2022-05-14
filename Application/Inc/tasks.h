#pragma once

#include "cmsis_os.h"

#include "common/mavlink.h"

/**
 * @brief 通用消息类型, 同时存储心跳包和命令两种消息, 用于统一队列数据类型
 *
 */
typedef struct __generic_message_t
{
  uint32_t msgid; //消息类型ID, 与MavLink的消息类型ID相同

  union
  {
    mavlink_heartbeat_t heartbeat;                   //心跳包
    mavlink_set_position_target_local_ned_t command; //控制命令
  };
} generic_message_t;

extern osThreadId_t debugTaskHandle;
extern osThreadId_t transmitMessagesTaskHandle;
extern osThreadId_t parseMessagesTaskHandle;
extern osMessageQueueId_t receivedBytesQueueHandle;
extern osMessageQueueId_t transmitMessagesQueueHandle;
extern osMessageQueueId_t heartbeatsQueueHandle;
extern osMessageQueueId_t commandsQueueHandle;
extern osTimerId_t sendHeartbeatsTimerHandle;
extern osSemaphoreId_t usbOccupationBinarySemHandle;
