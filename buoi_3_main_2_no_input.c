#include <stdio.h>
#include <stdarg.h>
/*khai báo thư viện "srdarg.h" dùng để sử dụng các hàm có đối số không xác định hoăc biến đổi
ví dụng như hàm va_lish, va_start */

int tinh_tong(int so_input,...)
{
    va_list va;     // "va_list": là 1 kiểu dữ liệu trong thư viện <stdarg.h> dùng để duyệt các đối số không xác định trong hàm
    va_start(va, so_input);// "va_start": là 1 macro trong thư viện <stdarg.h> dùng để kết hợp với hàm va_list khởi tạo con trỏ đến vị trí của đối số đầu tiên không xác định
    int sum = 0;
    for(int i = 0; i < so_input; i++)
    {
        printf("test : %d\n",va_arg(va, int));
    }

}
int main()
{
    tinh_tong(5,1,2,3,4,5);
    return 0;
}