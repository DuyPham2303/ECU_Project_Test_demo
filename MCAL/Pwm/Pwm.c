#include "Pwm.h"
#include "csv_io.h"
#include <stdio.h>
void Pwm_Init(void){
      printf("Cấu hình pin0 để xuất tín hiệu pwm\n");
}
void Pwm_SetDutyCycle(uint8_t channelId, uint16_t duty){
    if(channelId == 0){
        if(duty < 0) duty = 0;
        else if(duty > 100) duty = 100; 
        csv_setInt("duty",duty);
    }
    else{
        printf("pin %d chưa được config",channelId);
        return;
    }
}
