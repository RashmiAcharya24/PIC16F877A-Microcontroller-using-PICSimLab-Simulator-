/*
 * File:   main.c
 */

#include <xc.h>
#include "main.h"

#pragma config WDTE = OFF        // Watchdog Timer Enable bit (WDT enabled)

static void init_config(void) {
    TRISD=0;
    PORTD=0X00;
    SW1_DDR=1;
}

void main(void) {
    init_config();

    while (1) {
        if (SW1 == PRESSED)
        {
            LED1=!LED1;
        for(unsigned long int delay=50000;delay--;);
    }
}
    return;
}
