    #include <stdio.h>
    #include <stdint.h>

    typedef union 
    {
        uint32_t var1;
        uint16_t var2;
        uint64_t var3;
    }typeData;


    int main(int argc, char const *argv[])
    {
        typeData data = {.var1 = 5, .var2 = 7, .var3 = 8};

        printf("gia tri : %d\n",data.var3);
        printf("gia tri : %d\n",data.var2);
        printf("gia tri : %d\n",data.var1);

        printf("gia tri : %p\n",&data.var3);
        printf("gia tri : %p\n",&data.var2);
        printf("gia tri : %p\n",&data.var1);
        printf("gia tri : %p\n",&data);
        return 0;
    }
    
    