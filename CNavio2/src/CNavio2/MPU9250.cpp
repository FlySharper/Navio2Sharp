#ifndef CNAVIO2_MPU9250_CPP
#define CNAVIO2_MPU9250_CPP

#include <CNavio2/MPU9250.h>
#include <Navio/MPU9250.h>
#include <Navio/MPU9250.cpp>

struct nv2MPU9250
{
    MPU9250 instance;
};

nv2MPU9250* nv2MPU9250_Create()
{
    return new nv2MPU9250();
}

void nv2MPU9250_Destroy(nv2MPU9250* mpu9250)
{
    delete mpu9250;
}

bool nv2MPU9250_Initialize(nv2MPU9250* mpu9250)
{
    mpu9250->instance.initialize();
    return true;
}

bool nv2MPU9250_Probe(nv2MPU9250* mpu9250)
{
    return mpu9250->instance.probe();
}

void nv2MPU9250_Update(nv2MPU9250* mpu9250)
{
    mpu9250->instance.update();
}

float nv2MPU9250_ReadTemperature(nv2MPU9250* mpu9250)
{
    return mpu9250->instance.read_temperature();
}

void nv2MPU9250_ReadAccelerometer(nv2MPU9250* mpu9250, float *ax, float *ay, float *az)
{
    mpu9250->instance.read_accelerometer(ax, ay, az);
}

void nv2MPU9250_ReadGyroscope(nv2MPU9250* mpu9250, float *gx, float *gy, float *gz)
{
    mpu9250->instance.read_gyroscope(gx, gy, gz);
}

void nv2MPU9250_ReadMagnetometer(nv2MPU9250* mpu9250, float *mx, float *my, float *mz)
{
    mpu9250->instance.read_magnetometer(mx, my, mz);
}

#endif
