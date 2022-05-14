#pragma once

#define TX_BUF_SIZE 80

#include "common/mavlink.h"

/**
 * @brief 通用消息类型, 同时存储心跳包和命令两种消息, 用于统一队列数据类型
 *
 */
typedef struct __GenericMsg
{
  uint32_t msgid; //消息类型ID, 与MavLink的消息类型ID相同

  union
  {
    mavlink_heartbeat_t heartbeat;                   //心跳包
    mavlink_set_position_target_local_ned_t command; //控制命令
  };
} GenericMsg;

/**
 * @brief 启动通信功能
 * 
 */
void StartCommunication();

/**
 * @brief 停止通信功能
 * 
 */
void StopCommunication();
