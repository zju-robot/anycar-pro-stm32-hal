#pragma once

#include "main.h"

/**
 * @brief 所有回调函数的启动
 *
 */
void AnycarPro_CallbacksStart(void);

/**
 * @brief USB所用串口的接收回调
 *
 * @param huart 串口的句柄
 */
void USBUart_RxCpltCallback(UART_HandleTypeDef *huart);

/**
 * @brief USB所用串口的发送回调
 *
 * @param huart 串口的句柄
 */
void USBUart_TxCpltCallback(UART_HandleTypeDef *huart);
