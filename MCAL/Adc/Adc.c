#include "Adc.h"
#include "csv_io.h"
#include <stdio.h>
void Adc_Init(void)
{
    printf("Cấu hình pin1 là input để đọc tín hiệu adc từ cảm biến temp\n");
    printf("Cấu hình pin2 là input để đọc tín hiệu adc từ cảm biến voltage\n");
    printf("Cấu hình pin3 là input để đọc tín hiệu adc từ cảm biến current\n");
    printf("Cấu hình pin4 là input để đọc tín hiệu adc từ cảm biến torque\n");
    printf("Cấu hình pin5 là input để đọc tín hiệu adc từ cảm biến rpm\n");
}

uint16_t Adc_ReadChannel(uint8_t channelId){
    int value = 0;
    if(channelId == 1) value = csv_getInt("temp");
    else if(channelId == 2) value = csv_getInt("voltage");
    else if(channelId == 3) value = csv_getInt("current");
    else if(channelId == 4) value = csv_getInt("torque");
    else if(channelId == 5) value = csv_getInt("rpm");
    else{
        return -1;
    }
    return value;
}   
