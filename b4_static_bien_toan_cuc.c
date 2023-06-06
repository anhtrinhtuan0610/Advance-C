#include<stdio.h>
#include<stdint.h>
#include "b4_static_toan_cuc_test.c"

extern  uint8_t temp = 0; // khi ta gọi biến extern cũng không thể sử dụng được 
extern void dem();       // khi ta gọi biến extern cũng không thể sử dụng được 

int main()
{
    //printf("temp = %d",temp);
    test();
}

