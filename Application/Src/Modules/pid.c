#include "Modules/pid.h"

void PID_Init(PID_HandleTypeDef *hpid)
{
  hpid->output = 0;
  hpid->error = 0;
  hpid->sum = 0;
  hpid->diff = 0;
}

float PID_Step(PID_HandleTypeDef *hpid, float Error)
{
  float diff2 = hpid->diff;
  hpid->diff = Error - hpid->error;
  hpid->error = Error;
  hpid->output += hpid->param.kp *
                  (hpid->diff + hpid->param.dt / hpid->param.ti * hpid->error +
                   hpid->param.td / hpid->param.dt * diff2);
  return hpid->output;
}
