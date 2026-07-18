#include <xc.h>
#include "main.h"

void __interrupt() isr(void)
{
    if (TMR0IF == 1)
    {
        /* TMR0 Register valur + 251 (offset count to get 250 ticks) + 2 Inst Cycle */
        TMR0 = 251;

        LED1 = !LED1;
        
        TMR0IF = 0;
    }
}