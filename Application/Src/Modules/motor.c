#include "Modules/motor.h"

HAL_StatusTypeDef BDC_Start(BDC_HandleTypeDef *hbdc)
{
  HAL_StatusTypeDef status;
  if ((status = HAL_TIM_PWM_Start(hbdc->hsp.htimA, hbdc->hsp.channelA)) !=
      HAL_OK)
    return status;
  if ((status = HAL_TIM_PWM_Start(hbdc->hsp.htimB, hbdc->hsp.channelB)) !=
      HAL_OK)
    return status;
  return HAL_OK;
}

HAL_StatusTypeDef BDC_Stop(BDC_HandleTypeDef *hbdc)
{
  HAL_StatusTypeDef status;
  if ((status = HAL_TIM_PWM_Stop(hbdc->hsp.htimA, hbdc->hsp.channelA)) !=
      HAL_OK)
    return status;
  if ((status = HAL_TIM_PWM_Stop(hbdc->hsp.htimB, hbdc->hsp.channelB)) !=
      HAL_OK)
    return status;
  return HAL_OK;
}

void BDC_Drive(BDC_HandleTypeDef *hbdc, float duty)
{
  static uint32_t value;

  // 占空比限幅
  if (duty > 1)
    duty = 1;
  else if (duty < -1)
    duty = -1;

  // 记录本次驱动占空比
  hbdc->duty = duty;

  // 判断是否需要逆转方向
  if (hbdc->param.reverse)
    duty = -duty;

  // 根据旋转方向和占空比设置定时器比较匹配值
  if (duty > 0)
  {
    value = duty * __HAL_TIM_GET_AUTORELOAD(hbdc->hsp.htimA);
    __HAL_TIM_SET_COMPARE(hbdc->hsp.htimA, hbdc->hsp.channelA, value);
    __HAL_TIM_SET_COMPARE(hbdc->hsp.htimB, hbdc->hsp.channelB, 0);
  }
  else if (duty < 0)
  {
    value = -duty * __HAL_TIM_GET_AUTORELOAD(hbdc->hsp.htimB);
    __HAL_TIM_SET_COMPARE(hbdc->hsp.htimA, hbdc->hsp.channelA, 0);
    __HAL_TIM_SET_COMPARE(hbdc->hsp.htimB, hbdc->hsp.channelB, value);
  }
  else
  {
    __HAL_TIM_SET_COMPARE(hbdc->hsp.htimA, hbdc->hsp.channelA, 0);
    __HAL_TIM_SET_COMPARE(hbdc->hsp.htimB, hbdc->hsp.channelB, 0);
  }
}
