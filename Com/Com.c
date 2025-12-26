#include "Com.h"
#include <math.h>

/* 
    @brief struct lưu trữ dữ liệu sau khi decode để gửi cho Application sử dụng
*/
static struct{
    uint8_t id;
    uint8_t *data;
    uint8_t len;
}g_ENGINE_SPEED_Buffer;

//cờ quản lý trạng thái 
static bool SpeedReceived = false;
static bool StopRequest = false;

void Com_Init(){
    //Khởi tạo CanIf, PduR
}

// API nghiệp vụ lấy giá trị tốc độ động cơ (rpm) từ buffer
Std_ReturnType Com_EngineSpeed(uint16_t* rpm) {

        /* 
            kiểm tra cờ SpeedReceived đã được set
            nếu chưa được set -> return E_NOT_OK 
        */


        /*
            trả về giá trị tốc độ thực tế sau khi decode 
        */
       *rpm = g_ENGINE_SPEED_Buffer.data; //giả decode data = 120
       return E_OK;
}


// Hàm callback khi có frame mới
void Com_Indication(PduIdType pduId, uint8_t* data, uint8_t dlc) {
    if (pduId == PDU_ENGINE_SPEED) {
        /* 
            phân tách và chuyển đổi dữ liệu CAN sang giá trị số nguyên
        */
        
        uint8_t rpm; //biến lưu kết quả sau khi chuyển đổi

        /* 
            copy dữ liệu vào biến static lưu trữ dữ liệu tốc độ
        */
        g_ENGINE_SPEED_Buffer.data = rpm; //lưu tương tự cho dlc,id

        /* 
            cập nhật trạng thái đã nhận dữ liệu 
        */
        printf("[Com] Decoded feedback rpm = %d\n",
               rpm);
    }
    else{
        printf("[Com] Unknown command: 0x%02X\n", pduId);
    }
}