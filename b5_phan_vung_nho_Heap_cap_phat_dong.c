#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>  // thư viện dùng để khai báo các hàm cấp phát động

uint8_t array[] = {1,2,3,4}; // được gọi là "mạc tĩnh" tức là kích thước cố định không thay đổi

uint8_t *ptr;                //uint8_t : 1byte

int main(int argc, char const *argv[])
{
    uint16_t *ptr = (int16_t*)malloc(sizeof(int16_t)*5);   //malloc này là 5 byte

    for(int i = 0; i < 5; i++)
    {
            ptr[i] = 2*i;
    }

    for(int i = 0; i < 5; i++)
    {
        printf("i = %d\n",ptr[i]);
    }

    return 0;
}
