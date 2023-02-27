/* 
 * File:   main.c
 * Author: jford
 *
 * Created on February 9, 2023, 11:06 AM
 */

// CONFIG1L
#pragma config FEXTOSC = HS     // External Oscillator mode Selection bits (HS (crystal oscillator) above 8 MHz; PFM set to high power)
#pragma config RSTOSC = EXTOSC_4PLL// Power-up default value for COSC bits (EXTOSC with 4x PLL, with EXTOSC operating per FEXTOSC bits)

// CONFIG3L
#pragma config WDTE = OFF        // WDT operating mode (WDT enabled regardless of sleep)

#include <xc.h>
#include <stdio.h>
#include "serial.h"
#include "color.h"
#include "i2c.h"
#include "interrupts.h"
#define _XTAL_FREQ 64000000 //note intrinsic _delay function is 62.5ns at 64,000,000Hz  

extern volatile char DataFlag;

struct RGB_rel rel;
struct RGB vals;

void main(void) {
    initUSART4(); 
    Interrupts_init();
    color_click_init();
    I2C_2_Master_Init();
    char buf[50];
    unsigned int int_part;
    unsigned int frac_part;
    unsigned int ADC;
    
    while (1)
    {
<<<<<<< Updated upstream
           
    readColours(&vals);
    sprintf(buf,"red=%d green=%d blue=%d lum=%d\r\n",vals.R,vals.G,vals.B,vals.L);
=======
   LATGbits.LATG1=1;
    __delay_ms (100);
    
           
    readColours(&vals);
    colour_rel(&vals, &rel);
    
    sprintf(buf,"red=%f green=%f blue=%f lum=%d\r\n",rel.R, rel.G,rel.B,vals.L);
>>>>>>> Stashed changes
    TxBufferedString(buf);
    //sendTxBuf();
    while (DataFlag){
        sendTxBuf();
    } 

//    }
//    
}
}