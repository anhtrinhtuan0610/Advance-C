#include <stdio.h>
#include <stdint.h>

typedef union 
{
        
    uint8_t var1;     //hay là kiểu unsigned char 
    uint16_t var2;
    uint64_t var3;

}typeData;

int main(int argc, char const *argv[])
{
    typeData sz;
    sz.var2 = 1234;
   
    printf("var1 : %d, var3 : %d",sz.var1,sz.var3);

    return 0;
}
