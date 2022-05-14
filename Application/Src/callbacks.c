#include "callbacks.h"

#include "cmsis_os.h"
#include "main.h"

#include "anycar_pro.h"
#include "tasks.h"

static uint8_t receivedByte;

void AnycarPro_CallbacksStart(void)
{
  // USB串口初始化
  HAL_UART_Receive_IT(&USB_HUART, &receivedByte, 1);
}

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
  if (huart == &USB_HUART)
  {
    HAL_UART_Receive_IT(&USB_HUART, &receivedByte, 1); //开启下一次接收
    osMessageQueuePut(receivedBytesQueueHandle, &receivedByte, 0,
                      0); //压入本次收到的字节
  }
}

void HAL_UART_TxCpltCallback(UART_HandleTypeDef *huart)
{
  if (huart == &USB_HUART)
  {
    osSemaphoreRelease(usbOccupationBinarySemHandle); //解除对信号量的占用
  }
}
