#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>


int a = 10;
char b = 'C';
void tong()
{
    printf("ren roi noi di cung!");
}


int main(int argc, char const *argv[])
{
    int *ptr = &a;
    *ptr = 25;
    printf("chao buoi sang\n");
    printf("gia tri dia chi cua a la : %p\n",ptr);
    printf("gia tri dia chi cua b la : %p\n",&b);
    printf("gia tri dia chi cua tong la : %p\n",&tong);
    printf("gia tri cua a la : %d\n",a);
    printf("gia tri cua a la : %d\n",*ptr);
    return 0;
}
