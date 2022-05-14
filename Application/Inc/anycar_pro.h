#pragma once

#include "main.h"
#include "gpio.h"
#include "usart.h"
#include "spi.h"
#include "tim.h"

// 机械尺寸相关宏定义
#define WHEEL_DIAMETER (0.1f)
#define WHEEL_TREAD (0.2f)

// 电机相关宏定义
#define PWM_HTIM htim1 //产生两电机使用的四路PWM的定时器的句柄
#define MOTOR_L_CHANNEL_A TIM_CHANNEL_1 //左侧电机A相的PWM的定时器通道
#define MOTOR_L_CHANNEL_B TIM_CHANNEL_2 //左侧电机B相的PWM的定时器通道
#define MOTOR_R_CHANNEL_A TIM_CHANNEL_3 //右侧电机A相的PWM的定时器通道
#define MOTOR_R_CHANNEL_B TIM_CHANNEL_4 //右侧电机B相的PWM的定时器通道

#define ENCODER_L_HTIM htim3     //左侧编码器使用的定时器的句柄
#define ENCODER_R_HTIM htim2     //右侧编码器使用的定时器的句柄
#define ENCODER_RESOLUTION 60000 //编码器的线数

// 通信相关宏定义
#define USB_HUART huart2 //与Micro USB接口相连的串口的句柄
#define EXT_HUART huart1 //额外引出的串口的句柄
#define EXT_HSPI hspi1   //额外引出的SPI的句柄
