using System;
using System.Threading;
using Navio2Sharp;

namespace Example
{
    class Program
    {
        static void Main(string[] args)
        {
            var shouldRun = true;
            Console.CancelKeyPress += (sender, e) => { shouldRun = false; e.Cancel = true; };

            Console.WriteLine("Loading the MPU9250 sensor...");
            var mpu9250 = new MPU9250();

            while (shouldRun)
            {
                mpu9250.Update();

                Console.Write(string.Format("Acc: {0} {1} {2}  ", mpu9250.AX, mpu9250.AY, mpu9250.AZ));
                Console.Write(string.Format("Gyr: {0} {1} {2}  ", mpu9250.GX, mpu9250.GY, mpu9250.GZ));
                Console.WriteLine(string.Format("Mag: {0} {1} {2}", mpu9250.MX, mpu9250.MY, mpu9250.MZ));

                Thread.Sleep(1000);
            }

            Console.WriteLine("Disposing the MPU9250 sensor...");
            mpu9250.Dispose();

            Console.WriteLine("Goodbye!");
        }
    }
}
