#ifndef CANIF_H
#define CANIF_H

#include "StdTypes.h"

/* CAN ID hợp lệ theo tài liệu: 0x3F0 mang tốc độ động cơ */
#define CANID_ENGINE_SPEED   (0x3F0u)

/* PDU ID */
typedef uint16_t PduIdType;
#define PDU_ENGINE_SPEED     ((PduIdType)0) //quy đổi thành kiểu tiêu chuẩn mà không cần quan tầm protocol cụ thể

void CanIf_Init();
/*
 * @brief  Nhận frame can đã parse từ CAN Driver để đóng gói dữ liệu truyền đi
 * details thực hiện ánh xạ canId sang PduId và đóng gói lại thành cấu trúc chứa 
 *          ID + Data, trước khi gửi đến tằng PduR để định tuyến luồng thực thi
 * @param  canID ID can, ví dụ : 0x3F0
 * @param  data con trỏ đến dữ liệu (tối đa 8 byte)
 * @param  dlc  độ dài dữ liệu  (tối đa 8 byte)
 * @return Std_ReturnType trả về E_OK hoặc E_NOT_OK
 */
Std_ReturnType CanIf_Receive(uint32_t canId, uint8_t* data, uint8_t dlc);

#endif // CANIF_H
