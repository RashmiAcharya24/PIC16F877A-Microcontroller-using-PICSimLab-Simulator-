#include <xc.h>
#include "main.h"

void __interrupt() isr(void)
{
    static unsigned int count = 0;
    
    if (TMR2IF == 1)
    {
        if (++count == 125)
        {
            count = 0;
            
            LED1 = !LED1;
        }
        
        TMR2IF = 0;
    }
}