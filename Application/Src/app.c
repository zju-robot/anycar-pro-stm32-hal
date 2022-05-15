#include "tasks.h"
#include "communication.h"
#include "connection.h"
#include "motion_control.h"

/**
 * @brief 默认任务, 用于启动和调试
 *
 * @param argument FreeRTOS默认参数. 可无视
 */
void StartDefaultTask(void *argument)
{
  StartCommunication();
  StartConnection();
  StartMotionControl();

  for (;;)
  {
    osDelay(1);
  }
}
