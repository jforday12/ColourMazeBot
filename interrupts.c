#include <xc.h>
#include "interrupts.h"
#include "serial.h"




/************************************
 * Function to turn on interrupts and set if priority is used
 * Note you also need to enable peripheral interrupts in the INTCON register to use CM1IE.
************************************/
void Interrupts_init(void)
{
//    TRISBbits.TRISB1 = 1;   // Set TRIS value for pin RB1 (input)
//    ANSELBbits.ANSELB1 = 0; // Turn off analogue input for pin RB1
//    INT1PPS=0x09;
//    
//    PIE0bits.INT1IE = 1;    // Enable external interrupt source
//    PIR0bits.INT1IF = 0;
//    IPR0bits.INT1IP = 1;    // Set clear channel interrupt to high priority 
      
    //INTCONbits.INT0EDG = 0; 
    //colour_interrupt_init();
    
            
//    INTCONbits.IPEN=1;
//    PIE2bits.C1IE=1; 	//enable interrupt source INT0
//    INTCONbits.PEIE=1;
//    INTCONbits.GIE=1;//turn on interrupts globally (when this is off, all interrupts are deactivated)
//    PIE4bits.RC4IE=1;
    
}

//void clear_int(void){
//    I2C_2_Master_Start();            // Start condition
//	I2C_2_Master_Write(0x52 | 0x00); // 7 bit address + Write mode
//    I2C_2_Master_Write(0b11100110);        // Clear RGBC interrupt
//    I2C_2_Master_Stop();
//}
//void colour_interrupt_init(void){
//    clear_int(); // clear Interrupt flag
//    color_writetoaddr(0x00,0x13); // Enable interrupts
//    __delay_ms(3);   
//    color_writetoaddr(0x04,(low_threshold & 0x00FF));
//    color_writetoaddr(0x05,(low_threshold >>8));
//    color_writetoaddr(0x06, (high_threshold & 0x00FF));     
//    color_writetoaddr(0x07, (high_threshold >>8)); 
//    color_writetoaddr(0x0C, 0b0100); // interrupt will flag after 5 consecutive readings outside of range

//} 




/************************************
 * High priority interrupt service routine
 * Make sure all enabled interrupts are checked and flags cleared
************************************/
void __interrupt(high_priority) HighISR()
{
//    if (PIR4bits.TX4IF){
//        TX4REG = getCharFromTxBuf();
//    }
//    if (DataFlag & 0){
//        PIE4bits.TX4IE=0;
//    }
//    if (PIR4bits.RC4IF){
//        putCharToRxBuf(RC4REG);
//        //LCD_sendbyte(getCharFromRxBuf(),1);
//   }
//    
//    if (PIR0bits.INT1IF){
//        clear_int(); // Disable Interrupt
//        PIR0bits.INT1IF = 0;
//    }
//    
	//add your ISR code here i.e. check the flag, do something (i.e. toggle an LED), clear the flag...
}

