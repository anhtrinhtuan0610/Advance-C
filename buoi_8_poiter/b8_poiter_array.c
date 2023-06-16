#include <stdio.h>
#include <stdlib.h>


int a = 10;

char b = 'c';

void tong (int a, int b)
{
    printf("tong cua 2 so a va b la : %d",a+b);
}

int main(int argc, char const *argv[])
{
    void *arry[] = {&a, &b, &tong};

    printf("gia tri cua a la :%d\n", *(int *)arry[0]);
    printf("gia tri cua a la :%c\n", *(char *)arry[1]);
    
    int(*ptr)(int,int) = (void (*)(int,int))arry[2];
    int tong = ptr(5,8);
    

    return 0;
}
