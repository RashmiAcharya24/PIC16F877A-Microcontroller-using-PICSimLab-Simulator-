/*
 * File:   main.c
 */

#include <xc.h>
#include "main.h"
#include "digital_keypad.h"

#pragma config WDTE = OFF        // Watchdog Timer Enable bit (WDT enabled)

static void init_config(void) {
    LED_ARRAY1 = OFF;
    LED_ARRAY1_DDR = 0x00;
    
    init_digital_keypad();
}

void main(void) {
    unsigned char key;
    
    init_config();

    while (1) {
        key = read_digital_keypad(LEVEL);
     
      if (key == SW1)
        {
          RD0=!RD0;
          for(unsigned int delay=50000;delay--;);
        }
        else if (key == SW2)
        {
          RD1=!RD1;
          for(unsigned int delay=50000;delay--;);
          
        }
        else if (key == SW3)
        {
          RD2=!RD2;
          for(unsigned int delay=50000;delay--;);
          
        }
    
    }
    return;
}
