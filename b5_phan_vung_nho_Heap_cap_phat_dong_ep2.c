#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>  // thư viện dùng để khai báo các hàm cấp phát động


void test1()
{
    uint8_t array[5];
    printf("dia chi cua mang la : %p\n",array);
}

void test2()
{
    uint8_t *array =  (uint8_t*)malloc(sizeof(int16_t)*5);   //malloc này là 5 byte

    printf("dia chi cua mang la : %p\n",array);

    free(array);

}

int main(int argc, char const *argv[])
{
    test1();  //dia chi 2 thg nay giống nhau 
    test1();

    /*tại sao 2 thg này giống nhau
    vì nó là cấp phát tĩnh địa chỉ của nó sẽ không thay đổi 
    và nó được phân vùng nhớ stack
    stack thoát ra khỏi hàm sẽ thu hồi vùng nhớ */

    test2();  // địa chỉ 2 thg này khác nhau
    test2();

    /*tại sao 2 thg này lại có địa chỉ khác nhau 
    vì nó được lưu trên phân vùng nhớ Heap
    phân vùng Heap không có cơ chế tự phân vùng nhớ mà phải dùng hàm free để thu hồi vùng nhớ*/
    return 0;
}
