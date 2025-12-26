#ifndef IOHWAB_ADC_H
#define IOHWAB_ADC_H
#include "StdTypes.h"

Std_ReturnType IoHwAb_ReadTemp(uint16_t* temp_adc, float* temp_C);

Std_ReturnType IoHwAb_ReadVoltage(uint16_t* voltage_adc, float* voltage_V);

Std_ReturnType IoHwAb_ReadCurrent(uint16_t* current_adc, float* current_A);

Std_ReturnType IoHwAb_ReadTorque(uint16_t* torque_adc, float* torque_Nm);

Std_ReturnType IoHwAb_ReadRpm(uint16_t* rpm);
#endif // IOHWAB_ADC_H
