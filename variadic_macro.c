#include <stdio.h>

#define TEST(...) __VA_ARGS__
// đây là 1 macro được sử dụng khi ta chưa biết tham số đầu vào



int main()
{
    TEST(10, 20, 30);
    return 0;
}