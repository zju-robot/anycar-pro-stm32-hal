#include "motion_control.h"

#include <math.h>

#include "anycar_pro.h"

BDC_HandleTypeDef hbdcL = {.hsp = {.htimA = &PWM_HTIM,
                                   .channelA = MOTOR_L_CHANNEL_A,
                                   .htimB = &PWM_HTIM,
                                   .channelB = MOTOR_L_CHANNEL_B},
                           .param = {.reverse = 1}};
ENC_HandleTypeDef hencL = {
    .hsp = {.htim = &ENCODER_L_HTIM},
    .param = {.reverse = 0, .resolution = ENCODER_RESOLUTION}};
PID_HandleTypeDef hpidL = {
    .param = {.kp = 0.17f, .ti = 0.6f, .td = 0.0f, .dt = 0.01f}};

BDC_HandleTypeDef hbdcR = {.hsp = {.htimA = &PWM_HTIM,
                                   .channelA = MOTOR_R_CHANNEL_A,
                                   .htimB = &PWM_HTIM,
                                   .channelB = MOTOR_R_CHANNEL_B},
                           .param = {.reverse = 1}};
ENC_HandleTypeDef hencR = {
    .hsp = {.htim = &ENCODER_R_HTIM},
    .param = {.reverse = 1, .resolution = ENCODER_RESOLUTION}};
PID_HandleTypeDef hpidR = {
    .param = {.kp = 0.13f, .ti = 0.6f, .td = 0.0f, .dt = 0.01f}};

float motorLTargetRate = 0.0f;
float motorRTargetRate = 0.0f;

void MotorControlCallback(TIM_HandleTypeDef *htim)
{
  UNUSED(htim);

  ENC_Update(&hencL, 100);
  ENC_Update(&hencR, 100);

  PID_Step(&hpidL, motorLTargetRate - hencL.rate);
  PID_Step(&hpidR, motorRTargetRate - hencR.rate);

  BDC_Drive(&hbdcL, hpidL.output);
  BDC_Drive(&hbdcR, hpidR.output);
}

void StartMotionControl()
{
  BDC_Start(&hbdcL);
  ENC_Start(&hencL);
  PID_Init(&hpidL);

  BDC_Start(&hbdcR);
  ENC_Start(&hencR);
  PID_Init(&hpidR);

  htim6.PeriodElapsedCallback = MotorControlCallback;
  HAL_TIM_Base_Start_IT(&htim6);
}

void StopMotionControl()
{
  htim6.PeriodElapsedCallback = NULL;
  HAL_TIM_Base_Stop_IT(&htim6);

  BDC_Stop(&hbdcL);
  ENC_Stop(&hencL);

  BDC_Stop(&hbdcR);
  ENC_Stop(&hencR);
}

void SetTargetSpeed(const SpeedTypeDef *speed_ptr)
{
  motorLTargetRate =
      (speed_ptr->x_speed - speed_ptr->yaw_rate * WHEEL_TREAD / 2) /
      WHEEL_RADIUS;

  motorRTargetRate =
      (speed_ptr->x_speed + speed_ptr->yaw_rate * WHEEL_TREAD / 2) /
      WHEEL_RADIUS;
}

void GetCurrentSpeed(SpeedTypeDef *speed_ptr)
{
  speed_ptr->x_speed =
      (hencR.rate * WHEEL_RADIUS + hencL.rate * WHEEL_RADIUS) / 2;
  speed_ptr->yaw_rate =
      (hencR.rate * WHEEL_RADIUS - hencL.rate * WHEEL_RADIUS) / WHEEL_TREAD;
}

void SetMotorsTargetRate(float *rateL_ptr, float *rateR_ptr)
{
  motorLTargetRate = *rateL_ptr;
  motorRTargetRate = *rateR_ptr;
}

void GetCurrentMotorsRate(float *rateL_ptr, float *rateR_ptr)
{
  *rateL_ptr = hencL.rate;
  *rateR_ptr = hencR.rate;
}
