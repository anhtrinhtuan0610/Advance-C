#include <stdio.h>
#include <conio.h>
#include "test.c"
#define MIN 10 
void hienthi()
{
    printf("chao!");

}


int main()
{
    hienthi();
    printf("\n");
    display();
    printf("\n");
    printf("MIN = %d",MIN);
    getch();
    return 0;

}