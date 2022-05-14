#pragma once

#include "main.h"

// 描述编码器使用的相关外设
typedef struct
{
  TIM_HandleTypeDef *htim; //编码器使用的定时器的句柄
} ENC_HSPTypeDef;

// 描述编码器的物理参数
typedef struct
{
  uint8_t reverse;     //是否反向
  uint16_t resolution; //分辨率, 即编码器线数
} ENC_ParamTypeDef;

// 编码器句柄定义
typedef struct
{
  ENC_HSPTypeDef hsp;     //外设定义
  ENC_ParamTypeDef param; //物理参数
  int32_t cycles;         //旋转圈数
  float residue;          //除去完整圈数外剩余的角度
  float rate;             //转速
} ENC_HandleTypeDef;

/**
 * @brief 启动旋转编码器的各个硬件
 *
 * @param henc 旋转编码器的句柄的指针
 * @return HAL_StatusTypeDef 是否启动成功
 */
HAL_StatusTypeDef ENC_Start(ENC_HandleTypeDef *henc);

/**
 * @brief 停止旋转编码器的各个硬件
 *
 * @param henc 旋转编码器的句柄的指针
 * @return HAL_StatusTypeDef 是否停止成功
 */
HAL_StatusTypeDef ENC_Stop(ENC_HandleTypeDef *henc);

/**
 * @brief 读取硬件数据, 更新旋转编码器
 *
 * @param henc 旋转编码器的句柄的指针
 * @param freq 更新编码器的频率, 用于计算角速度; 若不需要则可设置为0
 */
void ENC_Update(ENC_HandleTypeDef *henc, float Freq);
