#ifndef CNAVIO2_EXPORT_H
#define CNAVIO2_EXPORT_H

#include <CNavio2/Config.h>

#if defined(CNAVIO2_EXPORTS)
    #define CNAVIO2_API CNAVIO2_API_EXPORT
#else
    #define CNAVIO2_API CNAVIO2_API_IMPORT
#endif

#endif
