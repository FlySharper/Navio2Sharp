using System;
using System.Runtime.InteropServices;

namespace Navio2Sharp
{
    public class RCInput : InternalBase
    {
        #region Constructor
        public RCInput() :
            base(Create())
        {
            if (Handle == IntPtr.Zero)
                throw new Exception("Failed to create a " + nameof(RCInput));

            Init(Handle);
        }
        #endregion

        #region Functions
        protected override void Destroy()
        {
            Destroy(Handle);
        }

        public int Read(int channel)
        {
            EnsureValid();

            return Read(Handle, channel);
        }
        #endregion

        #region Imports
        [DllImport(Config.CNavio2Lib, EntryPoint = "nv2RCInput_Create")]
        private static extern IntPtr Create();

        [DllImport(Config.CNavio2Lib, EntryPoint = "nv2RCInput_Destroy")]
        private static extern void Destroy(IntPtr handle);

        [DllImport(Config.CNavio2Lib, EntryPoint = "nv2RCInput_Init")]
        private static extern void Init(IntPtr handle);

        [DllImport(Config.CNavio2Lib, EntryPoint = "nv2RCInput_Read")]
        private static extern int Read(IntPtr handle, int channel);
        #endregion
    }
}
