#include <stdio.h>
#include <stdlib.h>   // để sử hàm exit thoát chương trình
#include <setjmp.h>   // thư viện "setjmp.h" trong c cung cấp các hàm để quản lý điểm nhảy trong chương trình


int main(int argc, char const *argv[])
{
    jmp_buf jumb;                 // tạo 1 biến theo kiểu jmp_buf
    int i = setjmp(jumb);           // tạo 1 điểm nhảy i 
    printf("i = %d\n",i);
    if(i != 0)
    {
        exit(0);
    }

    longjmp(jumb, 1);              // 
    return 0;
}
