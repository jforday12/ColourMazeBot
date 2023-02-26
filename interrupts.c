#include <xc.h>
#include "interrupts.h"
#include "serial.h"


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
    PIE4bits.RC4IE=1;
	// turn on global interrupts, peripheral interrupts and the interrupt source 
	// It's a good idea to turn on global interrupts last, once all other interrupt configuration is done.
}

/************************************
 * High priority interrupt service routine
 * Make sure all enabled interrupts are checked and flags cleared
************************************/
void __interrupt(high_priority) HighISR()
{
    if (PIR4bits.TX4IF){
        TX4REG = getCharFromTxBuf();
    }
    if (DataFlag & 0){
        PIE4bits.TX4IE=0;
    }
    if (PIR4bits.RC4IF){
        putCharToRxBuf(RC4REG);
        //LCD_sendbyte(getCharFromRxBuf(),1);
   }
    
	//add your ISR code here i.e. check the flag, do something (i.e. toggle an LED), clear the flag...
}

