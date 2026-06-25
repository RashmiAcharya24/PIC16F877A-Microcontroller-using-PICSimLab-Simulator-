/*
 * File:   main.c
 */

#include <xc.h>
#include "main.h"
#include "digital_keypad.h"
#include "pwm.h"

#pragma config WDTE = OFF        // Watchdog Timer Enable bit (WDT disabled)

#define MAX_DUTY              100

void pwm_control(unsigned char key)
{
    static unsigned char duty_cycle = 50;
    static unsigned int wait = 0;
    
    if (!wait--)
    {
        wait = 0;
        
        if (key == SW1)
        {
            if (duty_cycle != MAX_DUTY)
            {
                duty_cycle++;
            }
        }
        else if (key == SW2)
        {
            if (duty_cycle != 0)
            {
                duty_cycle--;
            }
        }
    }
    
    set_pwm_duty(duty_cycle); // 50%
}

static void init_config(void) {
    LED_ARRAY1 = 0x00;
    LED_ARRAY1_DDR = 0x00;
    
    init_digital_keypad();
    init_pwm();
}

void main(void) {
    unsigned char key;
    
    init_config();

    while (1) {
        key = read_digital_keypad(LEVEL);
        
        pwm_control(key);
        
        for (int i = 10000; i--; );
    }
    return;
}
