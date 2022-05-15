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
  static GenericMsg genericMsg = {.msgid = MAVLINK_MSG_ID_CONTROL_SYSTEM_STATE};

  GetCurrentSpeed(&speed);
  genericMsg.status.x_vel = speed.x_speed;
  genericMsg.status.yaw_rate = speed.yaw_rate;

  GetCurrentOdometry(&odom);
  genericMsg.status.x_pos = odom.x;
  genericMsg.status.y_pos = odom.y;
  genericMsg.status.q[0] = sinf(odom.yaw);
  genericMsg.status.q[1] = 0;
  genericMsg.status.q[2] = 0;
  genericMsg.status.q[3] = cosf(odom.yaw);

  osMessageQueuePut(transmitMessagesQueueHandle, &genericMsg, 0, 0);
}

void StartStatusReport() { osTimerStart(reportStatusTimerHandle, 100); }

void StopStatusReport() { osTimerStop(reportStatusTimerHandle); }
