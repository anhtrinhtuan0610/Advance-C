#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>


void swap(int a, int b)
{
    printf("gia tri cua bien a la : %d\n", a);
    printf("gia tri dia chi cua bien a la : %p\n",&a);


    printf("gia tri cua bien b la : %d\n", b);
    printf("gia tri dia chi cua bien b la : %p\n",&b);

    int temp = a;
    a = b; 
    b = temp;
}

void swap2(int *a, int*b)
{       
    printf("gia tri cua bien a la : %d\n", *a);
    printf("gia tri dia chi cua bien a la : %p\n",a);
    printf("\n");
    printf("gia tri cua bien b la : %d\n", *b);
    printf("gia tri dia chi cua bien b la : %p\n",b);
    int temp = *a;
    *b = *a;
    *b = temp;

}


int main(int argc, char const *argv[])
{
    int so1 = 10, so2 = 20;

    printf("\ngia tri cua so 1 la : %d\n",so1);
    printf("\ngia tri dia chi cua so 1 la : %p\n",&so1);

    printf("gia tri cua so 2 la : %d\n",so2);
    printf("gia tri dia chi cua so 2 la : %p",&so2);

    swap(so1,so2);

    swap2(&so1,&so2);
    

    return 0;
}
