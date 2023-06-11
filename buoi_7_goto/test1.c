#include <stdio.h>



int main(int argc, char const *argv[])
{
    int a;

    nhap:
    printf("vui long nhap vao a : ");
    scanf("%d",&a);

    if(a < 10)
    {

        goto nhap;                  // câu lệnh goto sẽ được thực hiện đến khi điều kiện trong if còn đúng

    }
    
    return 0;
}
