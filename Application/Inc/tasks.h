#pragma once

#include "cmsis_os.h"

extern osThreadId_t debugTaskHandle;
extern osThreadId_t transmitMessagesTaskHandle;
extern osThreadId_t parseMessagesTaskHandle;
extern osMessageQueueId_t receivedBytesQueueHandle;
extern osMessageQueueId_t transmitMessagesQueueHandle;
extern osMessageQueueId_t heartbeatsQueueHandle;
extern osMessageQueueId_t commandsQueueHandle;
extern osTimerId_t sendHeartbeatsTimerHandle;
extern osSemaphoreId_t usbOccupationBinarySemHandle;
