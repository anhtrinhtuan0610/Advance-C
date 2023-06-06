#include<stdio.h>
#include<stdint.h>
#include"b4_extern_test.c"

extern void count(); //khởi tạo biến extern sử dụng hàm count() trong file "b4_extern_test.c"

extern uint8_t temp; //khởi tạo biến extern sử dụng biến toàn cục temp.

// về bản chất là khi ta muốn sử dụng 1 hàm hay 1 biến toàn cục ở file khác cùng chung 1 folder thì ta sẽ sử dụng biến 

int main()
{
    count();
    count();
    temp = 20;
    printf("temp = %d\n",temp);
    count();
    return 0;
}
