using System;
using System.Runtime.InteropServices;

namespace Navio2Sharp
{
    public class PWM : InternalBase
    {
        #region Constructor
        public PWM() :
            base(Create())
        {
            if (Handle == IntPtr.Zero)
                throw new Exception("Failed to create a " + nameof(PWM));
        }
        #endregion

        #region Functions
        protected override void Destroy()
        {
            Destroy(Handle);
        }

        public void InitializeChannel(uint channel)
        {
            EnsureValid();

            if (!Init(Handle, channel))
                throw new Exception("Failed to init channel (ensure that you have root permissions)");

            if (!Enable(Handle, channel))
                throw new Exception("Failed to enable channel");
        }

        public void SetPeriod(uint channel, uint freq)
        {
            EnsureValid();

            if (!SetPeriod(Handle, channel, freq))
                throw new Exception("Failed to set period");
        }

        public void SetDutyCycle(uint channel, float period)
        {
            EnsureValid();

            if (!SetDutyCycle(Handle, channel, period))
                throw new Exception("Failed to set duty cycle");
        }
        #endregion

        #region Imports
        [DllImport(Config.CNavio2Lib, EntryPoint = "nv2PWM_Create")]
        private static extern IntPtr Create();

        [DllImport(Config.CNavio2Lib, EntryPoint = "nv2PWM_Destroy")]
        private static extern void Destroy(IntPtr handle);

        [DllImport(Config.CNavio2Lib, EntryPoint = "nv2PWM_Init")]
        private static extern bool Init(IntPtr handle, uint channel);

        [DllImport(Config.CNavio2Lib, EntryPoint = "nv2PWM_Enable")]
        private static extern bool Enable(IntPtr handle, uint channel);

        [DllImport(Config.CNavio2Lib, EntryPoint = "nv2PWM_SetPeriod")]
        private static extern bool SetPeriod(IntPtr handle, uint channel, uint freq);

        [DllImport(Config.CNavio2Lib, EntryPoint = "nv2PWM_SetDutyCycle")]
        private static extern bool SetDutyCycle(IntPtr handle, uint channel, float period);
        #endregion
    }
}
