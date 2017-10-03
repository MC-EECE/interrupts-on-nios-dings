
#include "io.h"
#include "system.h"
#include "alt_types.h"
#include "sys\alt_irq.h"
#include "timerISR.h"

/*******************************************************************************
 * int main()                                                                  *
 *                                                                             *
 ******************************************************************************/

volatile alt_u8 leading_zeros = 0x01&IORD(SLIDER_SWITCHES_BASE,0);

int main(void)
{ 
    /* Setup */
	alt_u32 * pCount;
	static alt_u32 count = 0;
	pCount = &count;

    /* Initialize Variables */

    /* Register ISRs */
	//alt_irq_register(PUSHBUTTONS_IRQ, ?, buttonISR);
	alt_irq_register(INTERVAL_TIMER_IRQ, (void*)pCount, timerISR);
    /* Initialize Timer */
	// Setup start value
    IOWR(INTERVAL_TIMER_BASE, 2, 0xFFFF&INTERVAL_TIMER_FREQ);
    IOWR(INTERVAL_TIMER_BASE, 3, 0xFFFF&(INTERVAL_TIMER_FREQ >> 16));
    // Start the timer
    IOWR(INTERVAL_TIMER_BASE, 1, 0x7); // Stop=0, Start=1, Cont=1, ITO=1 => 0111b = 0x7

    // Initialize the pushbuttons
    IOWR(PUSHBUTTONS_BASE, 2, 0XE); //1110b=E because pushbutton 0 is reset
    // Register the pushbutton ISR


    /* Loop while processing interrupts */
    while( 1 ) 
    {
    	//IOWR(RED_LEDS_BASE 0)
    }
    return 0; // should never get here
}
