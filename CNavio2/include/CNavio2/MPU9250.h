#ifndef CNAVIO2_MPU9250_H
#define CNAVIO2_MPU9250_H

#include <CNavio2/Export.h>
#include <CNavio2/Types.h>

CNAVIO2_API nv2MPU9250* nv2MPU9250_Create();

CNAVIO2_API void nv2MPU9250_Destroy(nv2MPU9250* mpu9250);

CNAVIO2_API bool nv2MPU9250_Initialize(nv2MPU9250* mpu9250);

CNAVIO2_API bool nv2MPU9250_Probe(nv2MPU9250* mpu9250);

CNAVIO2_API void nv2MPU9250_Update(nv2MPU9250* mpu9250);

CNAVIO2_API float nv2MPU9250_ReadTemperature(nv2MPU9250* mpu9250);

CNAVIO2_API void nv2MPU9250_ReadAccelerometer(nv2MPU9250* mpu9250, float *ax, float *ay, float *az);

CNAVIO2_API void nv2MPU9250_ReadGyroscope(nv2MPU9250* mpu9250, float *gx, float *gy, float *gz);

CNAVIO2_API void nv2MPU9250_ReadMagnetometer(nv2MPU9250* mpu9250, float *mx, float *my, float *mz);

#endif
