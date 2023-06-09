#include <stdio.h>
#include <stdint.h>

typedef union 
{
        
    uint8_t  var1[5];     //hay là kiểu unsigned char 
    uint16_t var2[2];
 

}typeData;

int main(int argc, char const *argv[])
{
    typeData sz;

    for(int i = 0; i < 5; i++)
    {
            sz.var1[i] = i;
    }
   
    for(int j = 0; j < 2; j++)
    {
        sz.var2[j] = 2*j;
    }

        for(int i = 0; i < 5; i++)
    {
            printf("test : %d\n",sz.var1[i]);
    }
          for(int j = 0; j < 2; j++)
    {
            printf("test2 : %d\n",sz.var2[j]);
    }
    return 0;
}
