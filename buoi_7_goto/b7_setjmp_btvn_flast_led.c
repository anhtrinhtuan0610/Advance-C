#include <stdio.h>
#include <stdlib.h>
#include <setjmp.h>


jmp_buf button;

int led_1 = 0;
int led_2 = 0;

#define PIN_1 button_1
#define PIN_2 button_2
#define PIN_3 stop

void delay_and_check_btn(int delay)
{
    for(int i = 0; i < delay; i++)
    {
        
    }
}

void chop_tat_led(int tan_suat)
{

    for(int  i = 0; i < tan_suat; i++)
    {
        led_1 = 0;
        delay_and_check_btn(100);
        led_2 = 1;
        delay_and_check_btn(100);
        led_2 = 0;
        delay_and_check_btn(100);
        led_1 = 1;
        delay_and_check_btn(100);

    }

}


void led_duoi(int tan_suat)
{
    for(int i = 0 ; i < tan_suat; i++)
    {
        led_1 = 0;
        delay_and_check_btn(100);
        led_2 = 1;
        delay_and_check_btn(100);
        led_1 = 1;
        delay_and_check_btn(100);

    }
}

void button_1()
{
    if(button_1 == 1)
    {
        chop_tat_led(5);
        longjmp(button,1);
    }

}


void button_2()
{
    if(button_2 == 1)
    {
        led_duoi(3);
        longjmp(button,1);
    }

}

void stop()
{
    if(stop == 1)
    {
        longjmp(button, 1);
    }
}

int  main()
{
    int i;
    i = setjmp(button);
    printf("%d\n",i);

    if(i == 0)
    {
        chop_tat_led(3);
        led_duoi(4);
        stop();

    }
    return 0;
}