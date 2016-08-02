#include <CNavio2/MPU9250.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
    printf("Opening the MPU9250 sensor...\n");
    nv2MPU9250* mpu9250 = nv2MPU9250_Create();

    if (!nv2MPU9250_Probe(mpu9250))
    {
        printf("Sensor is not enabled\n");
        return EXIT_FAILURE;
    }

    if (!nv2MPU9250_Initialize(mpu9250))
    {
        printf("Failed to initialize sensor\n");
        return EXIT_FAILURE;
    }

    printf("Sensor was successfully loaded\n");

    float ax, ay, az;
    float gx, gy, gz;
    float mx, my, mz;

    for (;;)
    {
        nv2MPU9250_Update(mpu9250);

        nv2MPU9250_ReadAccelerometer(mpu9250, &ax, &ay, &az);
        nv2MPU9250_ReadGyroscope(mpu9250, &gx, &gy, &gz);
        nv2MPU9250_ReadMagnetometer(mpu9250, &mx, &my, &mz);

        printf("Acc: %+7.3f %+7.3f %+7.3f  ", ax, ay, az);
        printf("Gyr: %+8.3f %+8.3f %+8.3f  ", gx, gy, gz);
        printf("Mag: %+7.3f %+7.3f %+7.3f\n", mx, my, mz);

        sleep(1);
    }

    printf("Closing the sensor...");
    nv2MPU9250_Destroy(mpu9250);

    return EXIT_SUCCESS;
}
