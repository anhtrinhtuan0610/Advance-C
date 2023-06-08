#include <stdio.h>
#include <stdint.h>


uint8_t tong(uint8_t a, uint8_t b)  // a và b ở đây được gọi la input parameter của hàm
{
    uint8_t c = 0;                  // c ở đây được gọi là biến cục bộ local

    c = a + b;

    printf("dia chi cua a la : %p\n",&a);      //"%p" để ghi địa chỉ
    printf("dia chi cua b la : %p\n",&b);
    printf("dia chi cua c la : %p\n",&c);

    return c;
}


int main()
{
    printf(" the sum of a and b is : %d\n",tong(5,6));
    /*uint8_t a = 5  địa chỉ : 0x01
      uint8_t b = 6  địa chỉ : 0x02
      uint8_t c = 5 + 6  địa chỉ : 0x03
    */
   return 0; 
}

/*tức là : tất cả những biến cục bộ và input parameter của hàm sẽ được phân vùng nhớ
trên vùng nhớ Stack*/