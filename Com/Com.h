#ifndef COM_H
#define COM_H

#include "StdTypes.h"
#include "CanIf.h"
#include "PduR.h"
void Com_Init();
Std_ReturnType Com_EngineSpeed(uint16_t* rpm);

#endif // COM_H
