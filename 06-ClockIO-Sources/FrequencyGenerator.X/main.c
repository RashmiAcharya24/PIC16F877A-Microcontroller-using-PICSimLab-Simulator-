/*
 * File:   main.c
 */

#include <xc.h>
#include "main.h"
#include "timers.h"
#include "digital_keypad.h"

#pragma config WDTE = OFF        // Watchdog Timer Enable bit (WDT disabled)

unsigned int req_time = 2000;

void frequency_control(unsigned char key)
{
    static unsigned char cur_freq = 5;
    
    if (key == SW1)
    {
        if (cur_freq != 10)
        {
            cur_freq++;
            req_time = (1.0 / cur_freq) * 10000;
        }
    }
    else if (key == SW2)
    {
        if (cur_freq != 1)
        {
            cur_freq--;
            req_time = (1.0 / cur_freq) * 10000;            
        }
    }
    
    LED_ARRAY1 = (LED_ARRAY1 & 0xF0) | cur_freq;
}

static void init_config(void) {
    LED_ARRAY1 = 0x00;
    LED_ARRAY1_DDR = 0x00;
    
    init_digital_keypad();
    init_timer0();
    
    /* Enable all the Global Interrupts */
    GIE = 1;
}

void main(void) {
    unsigned char key;
    
    init_config();

    while (1) {
        key = read_digital_keypad(STATE);
        
        frequency_control(key);
    }
    return;
}
