/*
 * File:   main.c
 * Author: CodeForThings
 * Description: This program will toggle the LEDs at PORTD
 * It illustrates coding practices and conventions used in this course.
 */

#include <xc.h>
#include "main.h"

#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled)

/* Function: init_config()
 * Description: This function is used to setup initial peripheral
 * configuration, like setting port directions, initializing port values
 */
static void init_config(void) {
    LED_ARRAY1_DDR = 0x00; // Set direction to o/p
    LED_ARRAY1 = 0x00;     // Set initial port value
}

void main(void) {
    unsigned int wait = 0;
    
    init_config();

    while (1) 
	{
		if(wait++ == 1000)
		{
			wait = 0;
			if(//condition for left ON)
			{
			    LED_ARRAY1 = ?	
			}
			if(//condition for left OFF)
			{
			    LED_ARRAY1 = ?	
			}
			if(//condition for right ON)
			{
			    LED_ARRAY1 = ?	
			}
			if(//condition for right OFF)
			{
			    LED_ARRAY1 = ?	
			}
			
		}
        
         }
    return;
}
