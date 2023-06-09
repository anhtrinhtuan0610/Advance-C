#include <stdio.h>
#include <stdint.h>

typedef union 
{
        
    uint32_t var1;
    uint16_t var2;
    uint64_t var3;

}typeData;



typedef union 
{
        
    uint32_t var1[3];
    uint16_t var2[7];
    uint64_t var3[4];

}typeData1;



int main(int argc, char const *argv[])
{
    typeData sz;
    typeData1 sz2;
    printf("kich thuoc cua union la : %d\n",sizeof(sz));
    printf("kich thuoc cua union la : %d\n",sizeof(sz2));

    return 0;
}


