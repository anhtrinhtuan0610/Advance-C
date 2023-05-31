#include <stdio.h>

#define VARIABLE(name)\
int int_##name;   \
char char_##name;  \
double double_##name

int main()
{
    VARIABLE(bien);
    int_bien = 10;
    char_bien = 'A';
    double_bien =10.6;
    printf("int : %d\n",int_bien);
    printf("char : %c\n",char_bien);
    printf("double : %f",double_bien);
}