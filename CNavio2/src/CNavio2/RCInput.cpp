#ifndef CNAVIO2_RCINPUT_CPP
#define CNAVIO2_RCINPUT_CPP

#include <CNavio2/RCInput.h>
#include <Navio/RCInput.h>
#include <Navio/RCInput.cpp>

struct nv2RCInput
{
	RCInput instance;
};

nv2RCInput* nv2RCInput_Create()
{
	return new nv2RCInput;
}

void nv2RCInput_Destroy(nv2RCInput* rcInput)
{
	delete rcInput;
}

void nv2RCInput_Init(nv2RCInput* rcInput)
{
	rcInput->instance.init();
}

int nv2RCInput_Read(nv2RCInput* rcInput, int channel)
{
	return rcInput->instance.read(channel);
}

#endif
