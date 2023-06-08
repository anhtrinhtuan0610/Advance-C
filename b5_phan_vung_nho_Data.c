#include <stdio.h>
#include <stdint.h>



uint8_t cal = 5; // đây là biến toàn cục

static uint8_t sal = 5; // đây là biến static với biến toàn cục tức là chỉ được sử dụng biến đó trong file này

void find()
{
    static uint8_t count = 5; //đây là biến static với biến cục bộ tức là biến này được cấp phát bộ nhớ trong suốt chương trình
}

int main(int argc, char const *argv[])
{
    cal = 6; // với phân vùng nhớ Data có thể đọc hoặc viết 
    printf("value = %d",cal);
    return 0;
}

/*tức là tất cả các biến toàn cục hoặc biến static 
được khai báo khác không sẽ được lưu ở phân vùng nhớ Data*/


