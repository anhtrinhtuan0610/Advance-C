#include <stdio.h>
#include <stdarg.h>

int  tong(int so_input, ...)
{
    int sum = 0;
    va_list va;                                     // thực chất là 1 con trỏ trỏ đến vị trí của đối số không xác định
    va_start (va,so_input);                         // khởi tạo con trỏ

    for(int i = 0; i < so_input; i++)
    {
      //  printf("test : %f\n", va_arg(va, double)); //chi chop in ra doi so co kieu double
        sum += va_arg(va,int);
        
    }
    va_end(va);                                       // xoa vung nho cua va_list
    return sum;
}

int main()
{
   // tong(5,1, (double)2, 3, 4, 5);
    printf("tong bang : %d",tong(6, 3, 6 ,9, 1, 2, 3));
    return 0;
}