#include "Dio.h"
#include "csv_io.h"
#include <stdio.h>


void Dio_Init(void){
    printf("Cấu hình pin0 để điều khiển chiểu quay động cơ\n");
}

void Dio_WriteChannel(uint8_t channelId, int level){

    if(channelId == 0){
        csv_setInt("direction",level);
        printf("đã ghi mức %s\tchiều quay:%s\n",(level == 1)? "HIGH" : "LOW", (level == 1) ? "Thuận" : "nghịch");
    }
    else{
        printf("pin %d chưa được config\n",channelId);
        return;
    }
}