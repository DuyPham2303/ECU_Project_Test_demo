#include "Can.h"
//#include "CanIf.h"
#include "csv_io.h"

/* Giả lập trạng thái controller: 0 = chưa init, 1 = đã init */
static int canInitialized = 0;
/* Lưu giữ con trỏ cấu hình hiện tại để có thể truy cập nếu cần */
static const Can_ConfigType *Can_ConfigPtr = NULL;

void Can_Init(const Can_ConfigType *ConfigPtr)
{
    if (ConfigPtr == NULL)
    {
        printf("[Can] ERROR: Null ConfigPtr passed to Can_Init\n");
        return;
    }
    Can_ConfigPtr = ConfigPtr;
    canInitialized = 1;
    printf("[Can] Initialized controller %u at baudrate %lu\n",
           (unsigned)ConfigPtr->ControllerConfig[0].ControllerId,
           (unsigned long)ConfigPtr->ControllerConfig[0].BaudRate);
}
/*
 * @brief  đọc can frame qua chuỗi ờ file.csv
 * details parse chuỗi dữ liệu chứa thông điệp Can,
 *         và lưu vào các trường (id,lc,data)
 * @param  canID 0x3F0 (mã nhận diện frame, ví dụ cho tốc độ động cơ)
 * @param  data 8 bytes payload (ví dụ: 03 80 25 00 00 00 00 00)
 * @param  dlc  8 (Data Length Code)
 * @return Std_ReturnType trả về E_OK hoặc E_NOT_OK
 */
Std_ReturnType Can_Receive(char* buf,uint32_t *canId, uint8_t *data, uint8_t *dlc){
    const char* temp = csv_getString("can");
    if(temp == NULL){
        return E_NOT_OK;
    }
    strncpy(buf,temp,strlen(temp)+1);
    return E_OK;

}

void Can_MainFunction_Read()
{
    char frame_str[64]; //mảng lưu trữ CAN frame đọc được
    
    //gọi hàm đọc chuỗi CAN từ file csv

    // in log kiểm tra chuỗi CAN đọc về

    // Khai báo nơi luu trữ parsed CAN FRAME
    uint32_t Id;
    uint8_t data[8];
    uint8_t dlc;

    // gọi hàm parse CAN FRAME
    if (Can_Receive(frame_str, &Id, &dlc, data) != E_OK)
    {
        // in log PARSE FAIL -> bỏ qua chuỗi hiẹn tại
    }

    // có thể in log kiểm tra dữ liệu đã parse

    // Đẩy dữ liệu đã parse lên CanIf

    //(void)CanIf_Receive(Id, data, dlc);
}
