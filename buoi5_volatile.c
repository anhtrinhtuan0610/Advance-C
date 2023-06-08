#include <stdio.h>
#include <stdint.h>
#include <time.h>


volatile uint8_t a;

volatile int test = 10;

void d();
void b();
void c();

int comment();

int main()
{
    while(1)
    {
        test = comment();
        d();
        b();
        c();
    }
}

