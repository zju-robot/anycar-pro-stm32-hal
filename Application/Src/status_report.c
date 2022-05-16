#include "status_report.h"

#include "tasks.h"
#include "communication.h"
#include "motion_control.h"

/**
 * @brief 定时循环发送当前速度的回调
 *
 * @param argument FreeRTOS默认参数. 可无视
 */
void ReportStatusCallback(void *argument)
{
  UNUSED(argument);

  static SpeedTypeDef speed;
  static OdomTypeDef odom;
  static GenericTxMsg genericTxMsg = {.msgid = MAVLINK_MSG_ID_MOTION_STATE};

  GetCurrentSpeed(&speed);
  genericTxMsg.motionState.xVel = speed.x_speed;
  genericTxMsg.motionState.yawRate = speed.yaw_rate;

  GetCurrentOdometry(&odom);
  genericTxMsg.motionState.x = odom.x;
  genericTxMsg.motionState.y = odom.y;
  genericTxMsg.motionState.yaw = odom.yaw;

  osMessageQueuePut(transmitMessagesQueueHandle, &genericTxMsg, 0, 10);
}

void StartStatusReport()
{
  osTimerStart(reportStatusTimerHandle, REPORT_PERIOD);
}

void StopStatusReport() { osTimerStop(reportStatusTimerHandle); }
