#include <xc.h>

void init_timer0(void)
{
    /* Setting the external clock source at T0CKI */
    T0CS = 1;
    
    /* Assinging the prescaler to Watchdog Timer */
    PSA = 1;

    TMR0 = 251;
    
    /* Selecting the Rising Edge Trigger */
    T0SE = 0;
    
    /* The timer interrupt is enabled */
    TMR0IE = 1;
}
