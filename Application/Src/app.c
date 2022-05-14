#include "tasks.h"
#include "communication.h"
#include "connection.h"

/**
 * @brief 默认任务, 用于启动和调试
 *
 * @param argument FreeRTOS默认参数. 可无视
 */
void StartDefaultTask(void *argument)
{
  StartCommunication();
  StartConnection();

  for (;;)
  {
    osDelay(1);
  }
}
