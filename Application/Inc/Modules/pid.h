#pragma once

typedef struct
{
  float kp;
  float ti;
  float td;
  float dt;
} PID_ParamTypeDef;

typedef struct
{
  PID_ParamTypeDef param;
  float error;
  float sum;
  float diff;
  float output;
} PID_HandleTypeDef;

/**
 * @brief 初始化PID组件
 *
 * @param hpid
 */
void PID_Init(PID_HandleTypeDef *hpid);

/**
 * @brief 计算一次PID控制
 *
 * @param hpid PID组件句柄指针
 * @param error 当前被控对象和目标值的误差
 * @return float 下一个周期的控制变量
 */
float PID_Step(PID_HandleTypeDef *hpid, float error);
