#ifndef CNAVIO2_MPU9250_CPP
#define CNAVIO2_MPU9250_CPP

#include <CNavio2/PWM.h>
#include <Navio/PWM.h>
#include <Navio/PWM.cpp>
#include <Navio/Util.h>
#include <Navio/Util.cpp>

struct nv2PWM
{
    PWM instance;
};

nv2PWM* nv2PWM_Create()
{
    return new nv2PWM;
}

void nv2PWM_Destroy(nv2PWM* pwm)
{
    delete pwm;
}

bool nv2PWM_Init(nv2PWM* pwm, unsigned int channel)
{
    return pwm->instance.init(channel);
}

bool nv2PWM_Enable(nv2PWM* pwm, unsigned int channel)
{
    return pwm->instance.enable(channel);
}

bool nv2PWM_SetPeriod(nv2PWM* pwm, unsigned int channel, unsigned int freq)
{
    return pwm->instance.set_period(channel, freq);
}

bool nv2PWM_SetDutyCycle(nv2PWM* pwm, unsigned int channel, float period)
{
    return pwm->instance.set_duty_cycle(channel, period);
}

#endif
