/*
 * File:   main.c
 * Author: Emertxe
 * Problem Statement : Write a Embedded C program to display the multiple patterns on the LEDs controlled by the switches.
 *                     For every switch, dedicate a LEDs glow pattern.The pattern should change on key press
 */


#include <xc.h>
#include "main.h"
#include "digital_keypad.h"

#pragma config WDTE = OFF

static void init_config(void) {
    /*To keep all LEDS OFF initially*/
    LED_ARRAY1 = OFF;
    
    /*To configure PORTD as output PORT*/
    LED_ARRAY1_DDR = 0x00; 
    
    /* Initializing digital keypad */
    init_digital_keypad();

}

void main(void) {
    //Variable declaration
    unsigned char key, key_copy;
    
    init_config();

    while (1) {
        
        /*To read key press*/
        key = read_digital_keypad(LEVEL);
        
        /*If switch is pressed, then only update key_copy*/
        if (key != ALL_RELEASED)
        {
            key_copy = key;
        }
        glow_on_press(key_copy);
    }

    return;
}

void glow_on_press(unsigned char key)
{
           
    unsigned char static flag = 0;
    static unsigned int wait = 0;
    wait++;
    if(key == SW1)
    {
        //Code for pattern1 same as assignment1
        //The LEDs should glow from Left to Right and Right to left as explained in the assignment-1.
    }
    else if(key == SW2)
    {
        //Code for pattern2
        //The LEDs should glow from left to Right and switch off from left to right, no direction control/ direction change
    }
    else if(key == SW3)
    {
        //Code for pattern3
        //The LEDs should blink alternately
    }
    else if( key == SW4)
    {
        //Code for pattern4
        //The LEDs has to blink nibble wise, i.e first 4 LEDs will be ON, next 4 LEDs will be OFF, 
        //after first 4 LEDs will be OFF, next 4 LEDs will be ON.
        if( wait == 50000)
        {
            wait = 0;
            flag = !flag;
            LED_ARRAY1 = 0xF0;  
        }
        if( flag)
        {
            LED_ARRAY1 = 0x0F;
        }
    
    }
    
}

