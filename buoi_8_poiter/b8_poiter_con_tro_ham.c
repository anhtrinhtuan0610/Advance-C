#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>


void tong(int a,int b)
{
    printf("tong cua %d va %d = %d\n",a,b,a+b);
}

void hieu(int a,int b)
{
    printf("hieu cua %d va %d = %d\n",a,b,a-b);
}

void tich(int a,int b)
{
    printf("tong cua %d va %d = %d\n",a,b,a*b);
}

void thuong(int a,int b)
{
    printf("thuong cua %d va %d = %.2f\n",a,b,(float)a/b);
}


void pheptinh(int a, int b, void(*ptr)(int,int))
{
    printf("phep tinh la : \n");
    ptr(a,b);
}

int main(int argc, char const *argv[])
{
    pheptinh(8, 6, &tong);
    pheptinh(8, 6, &hieu);
    pheptinh(8, 6, &tich);
    pheptinh(8, 6, &thuong);
    return 0;
}
