#include<stdio.h>
#include<stdint.h>


static uint8_t temp = 0; // khi mà biến toàn cục khai báo theo kiểu static thì chỉ có thể sử dụng trong file được khai báo 

static void dem()
{
    printf("dem = %d",temp);
}

void test()
{
    dem();
}