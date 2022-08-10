#ifndef CNAVIO2_RCINPUT_H
#define CNAVIO2_RCINPUT_H

#include <CNavio2/Export.h>
#include <CNavio2/Types.h>

CNAVIO2_API nv2RCInput* nv2RCInput_Create();

CNAVIO2_API void nv2RCInput_Destroy(nv2RCInput* rcInput);

CNAVIO2_API void nv2RCInput_Init(nv2RCInput* rcInput);

CNAVIO2_API int nv2RCInput_Read(nv2RCInput* rcInput, int channel);

#endif
