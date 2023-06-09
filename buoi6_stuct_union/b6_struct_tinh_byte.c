#include <stdio.h>
#include <stdint.h>


typedef struct 
{
    uint8_t  a;          // 1byte tronng 4byte thừa 3byte bộ nhớ đệm
    uint16_t b;          // 2byte so sánh với 3 byte > 2<3 > lưu vào bộ nhớ đệm thừa 1byte
    uint32_t c;          // 4byte so sánh với 1 byte bộ nhớ đệm > 4>1 > quét lần 2 4byte thừa 1 byte bộ nhớ đệm
}byte;

// tổng 4 byte + 4byte = 8byte

typedef struct 
{
    uint32_t  e;         // 4byte trong 4byte quét > đủ > không có bộ nhớ đệm
    uint8_t   f;         // quét lần 2 1byte vs 4byte quét > thừa 3byte bộ nhớ đệm  
    uint16_t  g;         // so sánh vs 3byte bộ nhớ đệm > 2byte<3byte > thừ 1 byte bộ nhớ đệm 
}count_byte;

// tổng 4 byte + 4byte = 8byte

typedef struct 
{
    uint32_t  i;         
    uint8_t   j;          
    uint32_t  k;         
    uint8_t   h; 
}count_byte2;


typedef struct 
{      
    uint8_t     day[3];       //8                    
    uint64_t   week[6];       //48
    uint32_t  month[4];       //16 
    uint16_t   year[5];       //16
}count_byte3;

/*cách tính byte theo kiểu struct nhưng là tính cho mảng
+ b1 : tách mảng thành các phần tử ví dụ ta có mảng uint8_t day[3] tách thành 3 biến 
uint8_t     day[0];
uint8_t     day[1];
uint8_t     day[2];
tương tựu với các mảng còn lại
+b2 tính toán giống với hướng dẫn tính theo biến
*/

//tổng là 88byte
typedef struct 
{      
//vì
//  uint64_t   date[2]; là mảng có phần tử có 8byte lớn nhất lên sẽ lấy 8byte làm vòng quét



    uint8_t     day[6];       //tách mảng thành các phần tử trong mảng
/*  uint8_t     day[0];       // 1/8 byte
    uint8_t     day[1];       // 1/7
    uint8_t     day[2];       // 1/6
    uint8_t     day[3];       // 1/5
    uint8_t     day[4];       // 1/4
    uint8_t     day[5];       // 1/3

    vòng quét đầu thừa 3 byte bộ nhớ đệm

*/  


    uint32_t  month[4];       //tách mảng
/*
    uint32_t  month[0];       // 4/8  
    uint32_t  month[1];       // 4/4
    uint32_t  month[2];       // 4/8
    uint32_t  month[3];       // 4/4

    vòng quét 2 8byte     dư 0
    vòng quét 3 8byte     dư 0
    
    tổng : 16 byte

*/


    uint16_t   year[3];       //tách mảng
/*
    uint16_t   year[0];       // 2/8
    uint16_t   year[1];       // 2/6
    uint16_t   year[2];       // 2/4

    vòng quét 4 : 8byte

*/


    uint64_t   date[2];       //tách mảng
/*
    uint64_t   date[0];       // 8/8byte
    uint64_t   date[1];       // 8/8

    vòng quét 5: 8byte
    vòng quét 6: 8byte
    tổng : 16byte
*/


}count_byte4;

int main(int argc, char const *argv[])
{
    byte date;
    count_byte cnt;
    count_byte2 nn;
    count_byte3 tt;
    count_byte4 xx;
    printf("size : %d\n",sizeof(date) );
    printf("size : %d\n",sizeof(cnt));
    printf("size : %d\n",sizeof(nn));
    printf("size : %d\n",sizeof(tt));
    printf("size : %d\n",sizeof(xx));
    return 0;
}
