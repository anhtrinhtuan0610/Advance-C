#include <stdio.h>
#include <stdint.h>
#include <string.h>



int main(int argc, char const *argv[])
{
    uint8_t phim  = 0;
    char ten[20];
    uint8_t tuoi;

    // yêu cầu kiểm tra xem tên nhập vào có hợp lệ hay không
    // tên chỉ chứa chữ cái

    // yêu cầu nhập tên và nhập tên
    printf("vui long nhap ten :");
    scanf("%s",ten);

    // kiểm tra tên có hợp lệ không!

    uint8_t len = strlen(ten);        // đo độ dài của chuỗi nhập vào 
    uint8_t hop_le = 1;               // tạo 1 biến hợp lệ
    for(int i = 0; i < len; i++)
    {
        if(!(ten[i] >= 'a' && ten[i] <= 'z') || (ten[i] >='A' && ten[i] <= 'Z'))
        {
            hop_le = 0;
            break;               // nếu không đúng thoát khỏi vòng lặp
        }

    }

    if(hop_le)
    {
        printf("ten hop le!");
    }
    else
    printf("ten khong hop le vui long nhap lai!");
    return 0;
}
