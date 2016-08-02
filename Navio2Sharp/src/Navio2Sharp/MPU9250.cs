using System;
using System.Runtime.InteropServices;

namespace Navio2Sharp
{
    public class MPU9250 : InternalBase
    {
        #region Constants
        private const string SensorName = nameof(MPU9250);
        #endregion

        #region Variables
        private float _ax, _ay, _az;
        private float _gx, _gy, _gz;
        private float _mx, _my, _mz;
        #endregion

        #region Properties
        public float Temperature
        {
            get
            {
                EnsureValid();

                return ReadTemperature(Handle);
            }
        }

        public float AX { get { return _ax; } }

        public float AY { get { return _az; } }

        public float AZ { get { return _az; } }

        public float GX { get { return _ax; } }

        public float GY { get { return _az; } }

        public float GZ { get { return _az; } }

        public float MX { get { return _mx; } }

        public float MY { get { return _mz; } }

        public float MZ { get { return _mz; } }
        #endregion

        #region Constructor
        public MPU9250() :
            base(Create())
        {
            if (Handle == IntPtr.Zero)
                throw new Exception("Failed to create the " + SensorName + "sensor");

            if (!Probe(Handle))
                throw new Exception(SensorName + " sensor is not enabled");

            if (!Initialize(Handle))
                throw new Exception("Failed to initialize the " + SensorName + " sensor");
        }
        #endregion

        #region Functions
        protected override void Destroy()
        {
            Destroy(Handle);
        }

        public void Update()
        {
            EnsureValid();

            Update(Handle);

            ReadAccelerometer(Handle, ref _ax, ref _ay, ref _az);
            ReadGyroscope(Handle, ref _gx, ref _gy, ref _gz);
            ReadMagnetometer(Handle, ref _mx, ref _my, ref _mz);
        }
        #endregion

        #region Imports
        [DllImport(Config.CNavio2Lib, EntryPoint = "nv2MPU9250_Create")]
        private static extern IntPtr Create();

        [DllImport(Config.CNavio2Lib, EntryPoint = "nv2MPU9250_Destroy")]
        private static extern void Destroy(IntPtr handle);

        [DllImport(Config.CNavio2Lib, EntryPoint = "nv2MPU9250_Initialize")]
        private static extern bool Initialize(IntPtr handle);

        [DllImport(Config.CNavio2Lib, EntryPoint = "nv2MPU9250_Probe")]
        private static extern bool Probe(IntPtr handle);

        [DllImport(Config.CNavio2Lib, EntryPoint = "nv2MPU9250_Update")]
        private static extern void Update(IntPtr handle);

        [DllImport(Config.CNavio2Lib, EntryPoint = "nv2MPU9250_ReadTemperature")]
        private static extern float ReadTemperature(IntPtr handle);

        [DllImport(Config.CNavio2Lib, EntryPoint = "nv2MPU9250_ReadAccelerometer")]
        private static extern void ReadAccelerometer(IntPtr handle, ref float ax, ref float ay, ref float az);

        [DllImport(Config.CNavio2Lib, EntryPoint = "nv2MPU9250_ReadGyroscope")]
        private static extern void ReadGyroscope(IntPtr handle, ref float gx, ref float gy, ref float gz);

        [DllImport(Config.CNavio2Lib, EntryPoint = "nv2MPU9250_ReadMagnetometer")]
        private static extern void ReadMagnetometer(IntPtr handle, ref float mx, ref float my, ref float mz);
        #endregion
    }
}
