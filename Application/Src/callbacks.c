#include "callbacks.h"

#include "cmsis_os.h"

#include "anycar_pro.h"
#include "tasks.h"

static uint8_t receivedByte;

void AnycarPro_CallbacksStart(void)
{
  // USB串口初始化
  USB_HUART.RxCpltCallback = USBUart_RxCpltCallback;
  USB_HUART.TxCpltCallback = USBUart_TxCpltCallback;
  HAL_UART_Receive_IT(&USB_HUART, &receivedByte, 1);
}

void USBUart_RxCpltCallback(UART_HandleTypeDef *huart)
{
  UNUSED(huart);

  HAL_UART_Receive_IT(&USB_HUART, &receivedByte, 1); //开启下一次接收
  osMessageQueuePut(receivedBytesQueueHandle, &receivedByte, 0,
                    0); //压入本次收到的字节
}

void USBUart_TxCpltCallback(UART_HandleTypeDef *huart)
{
  UNUSED(huart);

  osSemaphoreRelease(usbOccupationBinarySemHandle); //解除对信号量的占用
}
