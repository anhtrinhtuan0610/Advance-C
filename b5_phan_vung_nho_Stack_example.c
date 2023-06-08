#include <stdio.h>

void swap(int a, int b)
{
    int swap = a;
    a = b ;
    b = swap;
    printf("a = %d\n",a);
    printf("b = %d\n",b);
}

int main()
{
    int sodau = 10;
    int socuoi = 15;
    swap(sodau,socuoi); //khi thoát khỏi hàm thì bộ nhớ sẽ được thu hồi
    printf("so dau la :%d, so cuoi la :%d",sodau,socuoi);
}