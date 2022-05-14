#include "Modules/encoder.h"

HAL_StatusTypeDef ENC_Start(ENC_HandleTypeDef *henc)
{
  return HAL_TIM_Encoder_Start(henc->hsp.htim, TIM_CHANNEL_ALL);
}

HAL_StatusTypeDef ENC_Stop(ENC_HandleTypeDef *henc)
{
  return HAL_TIM_Encoder_Stop(henc->hsp.htim, TIM_CHANNEL_ALL);
}

typedef union
{
  int16_t signedValue;
  uint16_t unsignedValue;
} __Encoder_CounterTypeDef;

void ENC_Update(ENC_HandleTypeDef *henc, float freq)
{
  static __Encoder_CounterTypeDef count;
  static float cycle = 6.283185307179586F, delta;

  // 判断是否需要反转方向
  count.unsignedValue = __HAL_TIM_GET_COUNTER(henc->hsp.htim);
  if (henc->param.reverse)
    count.signedValue = -count.signedValue;

  // 重置硬件定时器
  henc->hsp.htim->Instance->CNT = 0;

  // 计算自上一次更新以来的角度变化量
  delta = count.signedValue * cycle / henc->param.resolution;

  // 更新编码器状态
  henc->residue += delta;
  for (; henc->residue > cycle; henc->cycles++)
    henc->residue -= cycle;
  for (; henc->residue < 0; henc->cycles--)
    henc->residue += cycle;
  henc->rate = delta * freq;
}
