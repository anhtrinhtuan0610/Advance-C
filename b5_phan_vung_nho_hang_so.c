#include <stdio.h>
#include <stdint.h>

const uint8_t temp = 15;  // đây là 1 hằng số được lưu trữ trên phân vừng nhớ test.

int main(int argc, char const *argv[])
{
    temp = 10;   // chỉ có thể xem giá trị của temp nhưng không thể sửa đổi giá trị của nó
    printf("temp = %d",temp);
    return 0;
}

/*tức là biến const sẽ đươc lưu trên phân vùng nhớ test 
và ta chỉ có thể đọc được nó chứ không thể nào sửa được nó*/