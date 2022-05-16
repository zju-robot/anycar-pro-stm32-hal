#pragma once

#define TX_BUF_SIZE 80

#include "messages/mavlink.h"

/**
 * @brief 通用消息类型, 同时存储所有类型消息, 用于统一队列数据类型
 *
 */
typedef struct __GenericTxMsg
{
  uint32_t msgid; //消息类型ID, 与MavLink的消息类型ID相同

  union
  {
    mavlink_heartbeat_t heartbeat;      //心跳包
    mavlink_motion_state_t motionState; //运动学状态反馈
  };
} GenericTxMsg;

typedef struct __GenericCmd
{
  uint32_t msgid;
  union
  {
    mavlink_set_speed_t setSpeed;            //控制命令
    mavlink_set_motors_rate_t setMotorsRate; //电机控制命令
    mavlink_set_odometry_t setOdometry;      //里程计重置命令
  };
} GenericCmd;

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
