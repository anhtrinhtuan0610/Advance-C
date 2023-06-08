#include <stdio.h>
#include <stdint.h>
#include <time.h>


int main()
{
    clock_t start, end;

    register uint32_t i;  //khi khai báo register trước variable thì thông báo rằng biến này sẽ được lưu trên bộ nhớ register

    start = clock();

    for(i = 0; i < 0xFFFFFFFF; i++)

    end = clock();

    printf("time : %f\n", (double)(end - start) /CLOCKS_PER_SEC);

    return 0;
}