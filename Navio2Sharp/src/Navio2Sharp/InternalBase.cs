using System;

namespace Navio2Sharp
{
    public abstract class InternalBase : IDisposable
    {
        #region Variables
        private IntPtr _handle;
        private bool _isDisposed = false;
        #endregion

        #region Properties
        protected IntPtr Handle
        {
            get
            {
                return _handle;
            }
        }

        public bool IsDisposed
        {
            get
            {
                return _isDisposed;
            }
        }
        #endregion

        #region Constructor
        internal InternalBase(IntPtr handle)
        {
            _handle = handle;
        }
        #endregion

        #region Destructor
        ~InternalBase()
        {
            Dispose();
        }
        #endregion

        #region Functions
        protected abstract void Destroy();

        public void Dispose()
        {
            if (!_isDisposed)
            {
                try
                {
                    Destroy();
                }
                catch (Exception e)
                {
                    #if DEBUG // only rethrow the exception if we are in debug mode
                        throw e;
                    #else
                        Console.WriteLine("Suppresed exception during Dispose() call - run in debug mode to throw the exception.");
                    #endif
                }
                finally
                {
                    _handle = IntPtr.Zero;
                }

                _isDisposed = true;
                GC.SuppressFinalize(this);
            }
        }

        protected void EnsureValid()
        {
            if (IsDisposed)
                throw new Exception("Attempt to access a disposed object");
        }
        #endregion
    }
}
