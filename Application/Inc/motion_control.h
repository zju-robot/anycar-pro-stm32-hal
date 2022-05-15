#pragma once

#include "Modules/encoder.h"
#include "Modules/motor.h"
#include "Modules/pid.h"

typedef struct __Speed
{
  float x_speed;
  float yaw_rate;
} SpeedTypeDef;

/**
 * @brief 启动电机控制
 *
 */
void StartMotionControl();

/**
 * @brief 停止电机控制
 *
 */
void StopMotionControl();

/**
 * @brief 设置车辆的目标速度
 *
 * @param speed_ptr 包含目标速度的结构体的指针
 */
void SetTargetSpeed(const SpeedTypeDef *speed_ptr);

/**
 * @brief 获得当前车辆的速度
 *
 * @param speed_ptr 将写入车辆速度的结构体的指针
 */
void GetCurrentSpeed(SpeedTypeDef *speed_ptr);

/**
 * @brief 直接设置左右两个电机的目标转速
 *
 * @param rateL_ptr 包含左侧电机目标转速的指针
 * @param rateR_ptr 包含右侧电机目标转速的指针
 */
void SetMotorsTargetRate(float *rateL_ptr, float *rateR_ptr);

/**
 * @brief 获得当前左右两个电机的转速
 *
 * @param rateL_ptr 将写入左侧电机当前转速的指针
 * @param rateR_ptr 将写入右侧电机当前转速的指针
 */
void GetCurrentMotorsRate(float *rateL_ptr, float *rateR_ptr);
