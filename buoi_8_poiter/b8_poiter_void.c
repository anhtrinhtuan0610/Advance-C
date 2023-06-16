#include <stdio.h>


int main(int argc, char const *argv[])
{
    int a = 10;
    char b = 'c';
    double c = 10.65;

    void *ptr = &a;
    printf("gia tri cua a la : %d\n",ptr);
    printf("gia tri cua a la : %d\n",*(int*)ptr);

    ptr = &b;
    printf("gia tri cua b la : %p\n",ptr);
    printf("gia tri cua b la : %c\n",*(char*)ptr);

    ptr = &c;
    printf("gia tri cua c la : %p\n",ptr);
    printf("gia tri cua b la : %.2f\n",*(double*)ptr);

    return 0;
}
