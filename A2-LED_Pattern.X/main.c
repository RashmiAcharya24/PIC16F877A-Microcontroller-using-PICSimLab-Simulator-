/*
 to toggle direction of train using digital keypad
 * File:   main.c
 */

#include <xc.h>
#include "main.h"
#include "digital_keypad.h"

#pragma config WDTE = OFF        // Watchdog Timer Enable bit (WDT enabled)

static void init_config(void) {
	
	/* Turn off LEDs initially */
	LED_ARRAY1 = 0x00;
	
	/* Configure as Ouput Port */
    	LED_ARRAY1_DDR  = 0X00;

	/* Initialize digital keypad */    	
	init_digital_keypad();
}

void main(void) {

    unsigned char key, flag = 1;
    unsigned int delay = 50000;
    
    init_config();

    while(1)
    {

		/* read digitalkeypad value store it in variable called key */
        	key = read_digital_keypad(STATE);
	
		/* remember key  holds value of key when pressed and 0x3f when released */
		
		if (key == SW1)
		{
        	  	/* take flag as variable to toggle the direction for pattern */
			flag = !flag;
        }
		
		/* use if loops don't use blocking loops 
		   in blocking codes u cannot detect keys */
				
		if (!delay--)
		{
			
			if (flag)
			{
        			/* Code for left to right pattern */	
			}
			if (flag == 0)
			{
				/* Code for right to left pattern */			
			}
			/* End of loop toggle flag to continue in other direction even key not pressed */
		}

     }
     return;
}
