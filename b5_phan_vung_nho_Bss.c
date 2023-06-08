#include <stdio.h>
#include <stdint.h>

static uint8_t a; // đây là biến static với biến toàn cục không được khởi tạo giá trị
uint8_t b = 0; // đây là biến toàn cục được khởi tạo bằng không 

int main(int argc, char const *argv[])
{
    a = 10;   // giống với phân vùng nhớ Data thì phân vùng nhớ Bss có thể đọc hoặc viết dữ liệu
    printf("temp = %d",a); 
    return 0;
}


/*tức khi khai báo biến toàn cục hoặc biến static mà không khởi tạo 
giá trị hoặc khởi tạo giá trị bằng không thì biến đó sẽ được phân vùng nhớ ở phân vùng nhớ Bss*/