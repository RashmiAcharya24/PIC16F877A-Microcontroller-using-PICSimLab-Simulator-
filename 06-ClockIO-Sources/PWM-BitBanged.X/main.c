    /*
     * File:   main.c
     */

    #include <xc.h>
    #include "main.h"
    #include "digital_keypad.h"

    #pragma config WDTE = OFF        // Watchdog Timer Enable bit (WDT disabled)

    #define PERIOD              100

    void software_pwm(unsigned char key)
    {
        static unsigned char duty_cycle = 50;
        static unsigned char loop_counter;
        static unsigned int wait = 0;

        if  (!wait--)
        {
            wait = 500;

            if (key == SW1)
            {
                if (duty_cycle != PERIOD)
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

        if (loop_counter <= duty_cycle)
        {
            LED1 = ON;
        }
        else
        {
            LED1 = OFF;
        }

        if (loop_counter == PERIOD)
        {
            loop_counter = 0;
        }

        loop_counter++;
    }

    static void init_config(void) {
        LED_ARRAY1 = 0x00;
        LED_ARRAY1_DDR = 0x00;

        init_digital_keypad();
    }

    void main(void) {
        unsigned char key;

        init_config();

        while (1) {
            key = read_digital_keypad(LEVEL);

            software_pwm(key);

           for (int i = 10000; i--; );
        }
        return;
    }
