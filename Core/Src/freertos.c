/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * File Name          : freertos.c
  * Description        : Code for freertos applications
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2022 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Includes ------------------------------------------------------------------*/
#include "FreeRTOS.h"
#include "task.h"
#include "main.h"
#include "cmsis_os.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
/* USER CODE BEGIN Variables */

/* USER CODE END Variables */
/* Definitions for defaultTask */
osThreadId_t defaultTaskHandle;
const osThreadAttr_t defaultTask_attributes = {
  .name = "defaultTask",
  .stack_size = 128 * 4,
  .priority = (osPriority_t) osPriorityLow,
};
/* Definitions for transmitMessagesTask */
osThreadId_t transmitMessagesTaskHandle;
const osThreadAttr_t transmitMessagesTask_attributes = {
  .name = "transmitMessagesTask",
  .stack_size = 160 * 4,
  .priority = (osPriority_t) osPriorityLow,
};
/* Definitions for parseMessagesTask */
osThreadId_t parseMessagesTaskHandle;
const osThreadAttr_t parseMessagesTask_attributes = {
  .name = "parseMessagesTask",
  .stack_size = 96 * 4,
  .priority = (osPriority_t) osPriorityLow,
};
/* Definitions for executeCommandsTask */
osThreadId_t executeCommandsTaskHandle;
const osThreadAttr_t executeCommandsTask_attributes = {
  .name = "executeCommandsTask",
  .stack_size = 96 * 4,
  .priority = (osPriority_t) osPriorityLow,
};
/* Definitions for checkConnectionTask */
osThreadId_t checkConnectionTaskHandle;
const osThreadAttr_t checkConnectionTask_attributes = {
  .name = "checkConnectionTask",
  .stack_size = 96 * 4,
  .priority = (osPriority_t) osPriorityLow,
};
/* Definitions for receivedBytesQueue */
osMessageQueueId_t receivedBytesQueueHandle;
const osMessageQueueAttr_t receivedBytesQueue_attributes = {
  .name = "receivedBytesQueue"
};
/* Definitions for transmitMessagesQueue */
osMessageQueueId_t transmitMessagesQueueHandle;
const osMessageQueueAttr_t transmitMessagesQueue_attributes = {
  .name = "transmitMessagesQueue"
};
/* Definitions for heartbeatsQueue */
osMessageQueueId_t heartbeatsQueueHandle;
const osMessageQueueAttr_t heartbeatsQueue_attributes = {
  .name = "heartbeatsQueue"
};
/* Definitions for commandsQueue */
osMessageQueueId_t commandsQueueHandle;
const osMessageQueueAttr_t commandsQueue_attributes = {
  .name = "commandsQueue"
};
/* Definitions for sendHeartbeatsTimer */
osTimerId_t sendHeartbeatsTimerHandle;
const osTimerAttr_t sendHeartbeatsTimer_attributes = {
  .name = "sendHeartbeatsTimer"
};
/* Definitions for reportStatusTimer */
osTimerId_t reportStatusTimerHandle;
const osTimerAttr_t reportStatusTimer_attributes = {
  .name = "reportStatusTimer"
};

/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN FunctionPrototypes */

/* USER CODE END FunctionPrototypes */

void StartDefaultTask(void *argument);
extern void StartTransmitMessagesTask(void *argument);
extern void StartParseMessagesTask(void *argument);
extern void StartExecuteCommandsTask(void *argument);
extern void StartCheckConnectionTask(void *argument);
extern void SendHeartbeatsCallback(void *argument);
extern void ReportStatusCallback(void *argument);

void MX_FREERTOS_Init(void); /* (MISRA C 2004 rule 8.1) */

/**
  * @brief  FreeRTOS initialization
  * @param  None
  * @retval None
  */
void MX_FREERTOS_Init(void) {
  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* USER CODE BEGIN RTOS_MUTEX */
  /* add mutexes, ... */
  /* USER CODE END RTOS_MUTEX */

  /* USER CODE BEGIN RTOS_SEMAPHORES */
  /* add semaphores, ... */
  /* USER CODE END RTOS_SEMAPHORES */

  /* Create the timer(s) */
  /* creation of sendHeartbeatsTimer */
  sendHeartbeatsTimerHandle = osTimerNew(SendHeartbeatsCallback, osTimerPeriodic, NULL, &sendHeartbeatsTimer_attributes);

  /* creation of reportStatusTimer */
  reportStatusTimerHandle = osTimerNew(ReportStatusCallback, osTimerPeriodic, NULL, &reportStatusTimer_attributes);

  /* USER CODE BEGIN RTOS_TIMERS */
  /* start timers, add new ones, ... */
  /* USER CODE END RTOS_TIMERS */

  /* Create the queue(s) */
  /* creation of receivedBytesQueue */
  receivedBytesQueueHandle = osMessageQueueNew (32, 1, &receivedBytesQueue_attributes);

  /* creation of transmitMessagesQueue */
  transmitMessagesQueueHandle = osMessageQueueNew (8, 32, &transmitMessagesQueue_attributes);

  /* creation of heartbeatsQueue */
  heartbeatsQueueHandle = osMessageQueueNew (4, 8, &heartbeatsQueue_attributes);

  /* creation of commandsQueue */
  commandsQueueHandle = osMessageQueueNew (4, 16, &commandsQueue_attributes);

  /* USER CODE BEGIN RTOS_QUEUES */
  /* add queues, ... */
  /* USER CODE END RTOS_QUEUES */

  /* Create the thread(s) */
  /* creation of defaultTask */
  defaultTaskHandle = osThreadNew(StartDefaultTask, NULL, &defaultTask_attributes);

  /* creation of transmitMessagesTask */
  transmitMessagesTaskHandle = osThreadNew(StartTransmitMessagesTask, NULL, &transmitMessagesTask_attributes);

  /* creation of parseMessagesTask */
  parseMessagesTaskHandle = osThreadNew(StartParseMessagesTask, NULL, &parseMessagesTask_attributes);

  /* creation of executeCommandsTask */
  executeCommandsTaskHandle = osThreadNew(StartExecuteCommandsTask, NULL, &executeCommandsTask_attributes);

  /* creation of checkConnectionTask */
  checkConnectionTaskHandle = osThreadNew(StartCheckConnectionTask, NULL, &checkConnectionTask_attributes);

  /* USER CODE BEGIN RTOS_THREADS */
  /* add threads, ... */
  /* USER CODE END RTOS_THREADS */

  /* USER CODE BEGIN RTOS_EVENTS */
  /* add events, ... */
  /* USER CODE END RTOS_EVENTS */

}

/* USER CODE BEGIN Header_StartDefaultTask */
/**
  * @brief  Function implementing the defaultTask thread.
  * @param  argument: Not used
  * @retval None
  */
/* USER CODE END Header_StartDefaultTask */
__weak void StartDefaultTask(void *argument)
{
  /* USER CODE BEGIN StartDefaultTask */
  /* Infinite loop */
  for(;;)
  {
    osDelay(1);
  }
  /* USER CODE END StartDefaultTask */
}

/* Private application code --------------------------------------------------*/
/* USER CODE BEGIN Application */

/* USER CODE END Application */

