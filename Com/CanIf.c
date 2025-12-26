#include "CanIf.h"
#include "Can.h"
#include <stdio.h>
/* Danh sách ID hợp lệ */
static const  PduIdType acceptList[] = {
    //...
};

/* Khai báo cấu hình CAN -> mặc định cho 1 controller cho ECU động cơ */
static const Can_ConfigType Can_Config = {
    //khởi tạo MCAL CAN driver với cấu hình Can_Config 
    //...    
    //in log
};

void CanIf_Init(){

}
/* 
    @brief Hàm lọc ID của gói CAN được phép xử lý
    @param canId id của gói CAN được CAN driver parse từ chuỗi text lấy trên file csv
    @return PduIdType   
    - trả về Id tương ứng trong bảng cấu hình nếu tìm thấy
    - trả về giá trị 0 nếu không tìm thấy
*/
static PduIdType CanIf_MatchPduIdFromCanId(uint32_t canId);

/*
 * @brief  Nhận frame can đã parse từ CAN Driver để đóng gói dữ liệu truyền đi
 * details thực hiện ánh xạ canId sang PduId và đóng gói lại thành cấu trúc chứa 
 *          ID + Data, trước khi gửi đến tằng PduR để định tuyến luồng thực thi
 * @param  canID ID can, ví dụ : 0x3F0
 * @param  data con trỏ đến dữ liệu (tối đa 8 byte)
 * @param  dlc  độ dài dữ liệu  (tối đa 8 byte)
 * @return Std_ReturnType trả về E_OK hoặc E_NOT_OK
 */


Std_ReturnType CanIf_Receive(uint32_t canId, uint8_t* data, uint8_t dlc){

    /* Lọc ID để đảm bảo chỉ xử lý những thông điệp CAN có ID hợp lệ   */
    PduIdType pduId = CanIf_MatchPduIdFromCanId(canId); 

    /* Kiểm tra nếu pduId hợp lệ 
        -> không phát hiện gói CAN  
        -> dừng xử lý tiếp 
        -> bỏ qua khung không nằm trong danh sách 
    */

    /* định tuyến (route) sang PduR -> điều phối gói CAN để xử lý yêu cầu*/
    PduR_RouteReceive(pduId, data, dlc);
    
}