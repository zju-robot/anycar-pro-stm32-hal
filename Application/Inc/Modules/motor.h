#pragma once

#include "main.h"

// 描述电机使用的相关外设
typedef struct
{
  TIM_HandleTypeDef *htimA; //第一路PWM使用的定时器
  uint32_t channelA;        //第一路PWM使用的通道
  GPIO_TypeDef *gpioA;      //第一路PWM使用的IO口所在组
  uint32_t pinA;            //第一路PWM使用的IO口编号
  TIM_HandleTypeDef *htimB; //第二路PWM使用的定时器
  uint32_t channelB;        //第二路PWM使用的通道
  GPIO_TypeDef *gpioB;      //第二路PWM使用的IO口所在组
  uint32_t pinB;            //第二路PWM使用的IO口编号
} BDC_HSPTypeDef;

// 描述电机的物理参数
typedef struct
{
  uint8_t reverse; //是否反向
} BDC_ParamTypeDef;

// 电机句柄定义
typedef struct
{
  BDC_HSPTypeDef hsp;     //外设定义
  BDC_ParamTypeDef param; //物理参数
  float duty;             //当前占空比
} BDC_HandleTypeDef;

/**
 * @brief 启动有刷直流电机的各个硬件
 *
 * @param hbdc 有刷直流电机的句柄
 * @return HAL_StatusTypeDef 是否启动成功
 */
HAL_StatusTypeDef BDC_Start(BDC_HandleTypeDef *hbdc);

/**
 * @brief 停止有刷直流电机的各个硬件
 *
 * @param hbdc 有刷直流电机的句柄
 * @return HAL_StatusTypeDef 是否停止成功
 */
HAL_StatusTypeDef BDC_Stop(BDC_HandleTypeDef *hbdc);

/**
 * @brief 按照给定占空比驱动有刷直流电机. 该占空比将存储在电机的句柄中
 *
 * @param hbdc 有刷直流电机的句柄
 * @param duty 输入给有刷直流电机的电流占空比;
 *             其正负可以控制电机的方向, 其大小可以控制电机的快慢
 */
void BDC_Drive(BDC_HandleTypeDef *hbdc, float duty);
