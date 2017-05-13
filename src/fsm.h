#ifndef FSM_H
#define FSM_H

#include "sysdefs.h"

#if defined(SIM_MODEL) && defined(WIN)
#define EXPORT __declspec(dllexport) 
#else
#define EXPORT
#endif

void EXPORT FSM_Init();

Actuators_t EXPORT FSM_Cycle(Sensors_t sensors); 

int EXPORT FSM_GetCycleTime();

#endif // FSM_H
