#include <xc.h>
#include "interrupts.h"
#include "serial.h"
#include "Memory.h"
#include"timers.h"
#include "dc_motor.h"
#include"color.h"

/************************************
 * Function to turn on interrupts and set if priority is used
 * Note you also need to enable peripheral interrupts in the INTCON register to use CM1IE.
************************************/
void Interrupts_init(void)
{
    INTCONbits.IPEN=0;
    PIE2bits.C1IE=1; 	//enable interrupt source INT0
    INTCONbits.PEIE=1;
    INTCONbits.GIE=1;//turn on interrupts globally (when this is off, all interrupts are deactivated)
    PIE0bits.TMR0IE=1;
	// turn on global interrupts, peripheral interrupts and the interrupt source 
	// It's a good idea to turn on global interrupts last, once all other interrupt configuration is done.
}

/************************************
 * High priority interrupt service routine
 * Make sure all enabled interrupts are checked and flags cleared
************************************/
void __interrupt(high_priority) HighISR()
{
    if (PIR0bits.TMR0IF){
        move_count++; // increment index of move and timer arrays
        Time_forward[move_count]=65535;
        PIR0bits.TMR0IF=0;
        PIE0bits.TMR0IE = 0; 
        go_Home(WayBack, Time_forward);
        
    }

    
	//add your ISR code here i.e. check the flag, do something (i.e. toggle an LED), clear the flag...
}