#include <stdio.h>
#define VARIABLE(type, name) type name

int main()
{
    VARIABLE(int , bien);
    bien = 10;
    printf("tesst = %d",bien);
}