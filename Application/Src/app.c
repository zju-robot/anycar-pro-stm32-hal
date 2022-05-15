#include "tasks.h"
#include "communication.h"
#include "connection.h"
#include "motion_control.h"
#include "status_report.h"

#include "anycar_pro.h"

/**
 * @brief 默认任务, 用于启动和调试
 *
 * @param argument FreeRTOS默认参数. 可无视
 */
void StartDefaultTask(void *argument)
{
  static int defaultTaskStackSpace;
  static int transmitMessagesTaskStackSpace;
  static int parseMessagesTaskStackSpace;
  static int executeCommandsTaskStackSpace;

  static uint8_t buf[40];

  StartCommunication();
  StartConnection();
  StartMotionControl();
  StartStatusReport();

  for (;;)
  {
    osDelay(1000);

    defaultTaskStackSpace = osThreadGetStackSpace(defaultTaskHandle);
    transmitMessagesTaskStackSpace =
        osThreadGetStackSpace(transmitMessagesTaskHandle);
    parseMessagesTaskStackSpace =
        osThreadGetStackSpace(parseMessagesTaskHandle);
    executeCommandsTaskStackSpace =
        osThreadGetStackSpace(executeCommandsTaskHandle);

    sprintf((char *)buf, "d: -%d, tm: -%d, pm: -%d, ec: -%d\n",
            defaultTaskStackSpace, transmitMessagesTaskStackSpace,
            parseMessagesTaskStackSpace, executeCommandsTaskStackSpace);
    HAL_UART_Transmit_IT(&USB_HUART, buf, strlen((char *)buf));
  }
}

/**
 * @brief 命令执行任务
 *
 * @param argument FreeRTOS默认参数. 可无视
 */
void StartExecuteCommandsTask(void *argument)
{
  UNUSED(argument);

  static mavlink_set_position_target_local_ned_t cmdMsg;
  static SpeedTypeDef targetSpeed;

  for (;;)
  {
    osMessageQueueGet(commandsQueueHandle, &cmdMsg, 0, osWaitForever);

    targetSpeed.x_speed = cmdMsg.vx;
    targetSpeed.yaw_rate = cmdMsg.yaw_rate;
    SetTargetSpeed(&targetSpeed);
  }
}
