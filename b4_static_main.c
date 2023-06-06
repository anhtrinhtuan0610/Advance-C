#include <stdio.h>
#include <stdint.h>   // thư viện giúp lưu trữ và làm việc với dữ liệu 1 cách hiệu quả ở cấp độ bit


void count()
{
    uint8_t temp = 0;
    printf("temp = %d\n",temp);
    temp++;
}

void count_2()
{
    static uint8_t temp = 0;
    printf("temp = %d\n",temp);
    temp++;
}
int main()
{
    count();
    count();
    count();

    count_2();
    count_2();
    count_2();
    return 0;
}