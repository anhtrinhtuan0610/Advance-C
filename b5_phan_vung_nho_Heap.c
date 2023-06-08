#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>  // thư viện dùng để khai báo các hàm cấp phát động

uint8_t array[] = {1,2,3,4}; // được gọi là "mạc tĩnh" tức là kích thước cố định không thay đổi

uint8_t *ptr;

int main(int argc, char const *argv[])
{
    ptr = array;
    printf("gia tri : %d", ptr[1]); 
    return 0;
}
