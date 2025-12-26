/***************************************************************************
 * @file    CAN_h
 * @brief   file này cung cấp các API để Mô phỏng truyền/nhận frame CAN qua chuỗi ở file csv
 * @version 1.0
 * @date    2024-09-11
 * @author  HALA Academy
 * @website https://hala.edu.vn/
 ***************************************************************************/
#ifndef CAN_H
#define CAN_H
#include "StdTypes.h"
#include <string.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
/**
 * @brief   Cấu trúc tối giản cho CAN driver (MCAL).
 *          Chỉ chứa duy nhất một controller.
 */
typedef struct {
    struct {
        uint8_t  ControllerId;   /* ID của controller (ví dụ 0) */
        uint32_t BaudRate;       /* Baudrate, ví dụ 500000 */
    } ControllerConfig[1];
} Can_ConfigType;
/*
 * @brief   Khởi tạo giao thức CAN 
 * @return  void
 */
void Can_Init(const Can_ConfigType *ConfigPtr);

//Hàm gọi loop liên tục để đọc CAN frame
void Can_MainFunction_Read();

Std_ReturnType Can_Receive(char* buf,uint32_t *canId, uint8_t *data, uint8_t *dlc);

#endif // CAN_H
