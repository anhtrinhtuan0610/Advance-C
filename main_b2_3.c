#include <stdio.h>

#define hien_thi(ten_ham, ten_hoc_sinh, tuoi, lop) \
void ten_ham(){                                    \
    printf("ten : %s\n",#ten_hoc_sinh);               \
    printf("tuoi : %d\n", tuoi);                     \
    printf("lop : %d\n", lop);                       \
}
hien_thi(nguyen_A,Nguyen va A, 16, 9)
hien_thi(nguyen_B,Nguyen va B, 17, 10)
int main()
{
    nguyen_A();
    nguyen_B();
    return 0;
}