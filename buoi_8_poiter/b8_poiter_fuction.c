#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>


void tong(int a,int b)
{
    printf("tong cua %d va %d = %d\n",a,b,a+b);
}

float thuong(float a ,float b)
{
    return a*b;
}

int main(int argc, char const *argv[])
{
    void(*ptr)(int,int);
    ptr = &tong;
    ptr(8,10);
    ((void (*)(int, int))ptr)(9,7);

    float(*ptr1)(float,float);
    ptr1 = &thuong;
    printf("thuong cua a va b la : %.2f",ptr1(1.2,2.1));
    return 0;
}
