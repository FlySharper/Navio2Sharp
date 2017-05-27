#ifndef CNAVIO2_MPU9250_H
#define CNAVIO2_MPU9250_H

#include <CNavio2/Export.h>
#include <CNavio2/Types.h>

CNAVIO2_API nv2PWM* nv2PWM_Create();

CNAVIO2_API void nv2PWM_Destroy(nv2PWM* pwm);

CNAVIO2_API bool nv2PWM_Init(nv2PWM* pwm, unsigned int channel);

CNAVIO2_API bool nv2PWM_Enable(nv2PWM* pwm, unsigned int channel);

CNAVIO2_API bool nv2PWM_SetPeriod(nv2PWM* pwm, unsigned int channel, unsigned int freq);

CNAVIO2_API bool nv2PWM_SetDutyCycle(nv2PWM* pwm, unsigned int channel, float period);

#endif
