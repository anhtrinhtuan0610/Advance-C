#include <stdio.h>
#include <stdint.h>
#include <string.h>



int main(int argc, char const *argv[])
{
    uint8_t phim  = 0;
    char ten[20];
    uint8_t tuoi;

    vi_tri_ten:
    printf("nhap ten : ");
    scanf("%s",ten);

    if(0)
    {
        goto vi_tri_ten;                       // chỉ thực hiện lệnh goto khi diều kiện bên trên là sai
    }

    vi_tri_tuoi:
    printf("tuoi :");
    scanf("%d",tuoi);

    if(tuoi < 10)
    {
        goto vi_tri_tuoi;
    }
    return 0;
}