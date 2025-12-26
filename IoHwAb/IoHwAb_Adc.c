#include "IoHwAb_Adc.h"
#include "Adc.h"
#include "csv_io.h"

#define ADC_12BIT   4095
#define VREAF       5

#define MAX_TEMP    200
#define MAX_VOLTAGE 60
#define MAX_CURRENT 50
#define MAX_TORQUE  120

#define CHANNEL_TEMP 1
#define CHANNEL_VOLTAGE 2
#define CHANNEL_CURRENT 3
#define CHANNEL_TORQUE 4
#define CHANNEL_RPM 5

Std_ReturnType IoHwAb_ReadTemp(uint16_t* temp_adc, float* temp_C){
    *temp_adc = Adc_ReadChannel(CHANNEL_TEMP);

    if(*temp_adc == NULL){
        return E_NOT_OK;
    }

    *temp_C = (*temp_adc) * MAX_TEMP / ADC_12BIT;

    return E_OK;
}

Std_ReturnType IoHwAb_ReadVoltage(uint16_t* voltage_adc, float* voltage_V){
    *voltage_adc = Adc_ReadChannel(CHANNEL_VOLTAGE);
    if(voltage_adc == NULL){
        return E_NOT_OK;
    }
    *voltage_V = (*voltage_adc) * MAX_VOLTAGE / ADC_12BIT;
    return E_OK;
}

Std_ReturnType IoHwAb_ReadCurrent(uint16_t* current_adc, float* current_A){
    *current_adc = Adc_ReadChannel(CHANNEL_VOLTAGE);
    if(current_adc == NULL){
        return E_NOT_OK;
    }
    *current_A = (*current_adc) * MAX_CURRENT / ADC_12BIT;
    return E_OK;
}

Std_ReturnType IoHwAb_ReadTorque(uint16_t* torque_adc, float* torque_Nm){
     *torque_adc = Adc_ReadChannel(CHANNEL_VOLTAGE);
    if(torque_adc == NULL){
        return E_NOT_OK;
    }
    *torque_Nm = (*torque_adc) * MAX_CURRENT / ADC_12BIT;
    return E_OK;
}

Std_ReturnType IoHwAb_ReadRpm(uint16_t* rpm){
    *rpm = csv_getInt("rpm");
    if(rpm == NULL){
        return E_NOT_OK;
    }
    return E_OK;
}

