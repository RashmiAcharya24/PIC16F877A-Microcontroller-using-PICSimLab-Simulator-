/*
 * File:   main.c
 */

#include <xc.h>
#include "uart.h"

#pragma config WDTE = OFF        // Watchdog Timer Enable bit (WDT disabled)

#define LED_ARARY1          PORTD
#define LED_ARRAY1_DDR      TRISD
#define LED1                RD0

extern unsigned char ch;

static void init_config(void) {
    LED_ARARY1 = 0x00;
    LED_ARRAY1_DDR = 0x00;
    
    init_uart(9600);
    
    puts("UART Test Code\n\r");
    
    /* Enabling peripheral interrupt */
    PEIE = 1;
    
    /* Enabling global interrupt */
    GIE = 1;
}

void main(void) {
    unsigned short wait = 0;
    
    init_config();

    while (1) {
        if (ch != '\0')
        {
            putchar(ch);
            
            ch = '\0';
        }
        
        if (!wait--)
        {
            wait = 50000;
            
            LED1 = !LED1;
        }
    }
    
    return;
}
