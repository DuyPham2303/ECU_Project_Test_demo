#include "PduR.h"
#include "Com.h"

void PduR_Init(){
    //in log
}
/*
 * @brief  nhận gói PDU từ CanIf
 * details định tuyến đến Com (theo cấu hình mapping), dựa trên loại giao thức sử dụng
 *         Can,Lin,Flexray
 * @param  canID ID can, ví dụ : 0x3F0
 * @param  data con trỏ đến dữ liệu (tối đa 8 byte)
 * @param  dlc  độ dài dữ liệu  (tối đa 8 byte)
 * @return Std_ReturnType trả về E_OK hoặc E_NOT_OK
 */
Std_ReturnType PduR_RouteReceive(PduIdType pduId, uint8_t* data, uint8_t dlc){

    /* 
        kiểm tra trên bảng mapping 
        -> xác định nguồn protocol gửi gói can CAN/LIN/FLEXRAY
        -> ảnh xạ đến Module xử lý nào Com/DCM/FIM
    */
    Com_Indication(pduId, data, dlc); 
}