#ifndef CNAVIO2_CONFIG_H
#define CNAVIO2_CONFIG_H

#if defined(_WIN32) || defined(__WIN32__)
    #define CNAVIO2_SYSTEM_WINDOWS
#elif defined(linux) || defined(__linux)
    #define CNAVIO2_SYSTEM_LINUX
#elif defined(__APPLE__) || defined(MACOSX) || defined(macintosh) || defined(Macintosh)
    #define CNAVIO2_SYSTEM_MACOS
#elif defined(__FreeBSD__) || defined(__FreeBSD_kernel__)
    #define CNAVIO2_SYSTEM_FREEBSD
#else
    #error This operating system is not supported
#endif

#if defined(CNAVIO2_SYSTEM_WINDOWS)
    #define CNAVIO2_API_EXPORT extern "C" __declspec(dllexport)
    #define CNAVIO2_API_IMPORT extern "C" __declspec(dllimport)
    #ifdef _MSC_VER
        #pragma warning(disable : 4251)
    #endif
#else
    #if __GNUC__ >= 4
        #define CNAVIO2_API_EXPORT extern "C" __attribute__ ((__visibility__ ("default")))
        #define CNAVIO2_API_IMPORT extern "C" __attribute__ ((__visibility__ ("default")))
    #else
        #define CNAVIO2_API_EXPORT extern "C"
        #define CNAVIO2_API_IMPORT extern "C"
    #endif
#endif

#endif
