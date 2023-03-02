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
    
    
	//tmp=I2C_2_Master_Read(1);			//read the Red LSB
	//tmp=tmp | (I2C_2_Master_Read(0)<<8); //read the Red MSB (don't acknowledge as this is the last read)
    
	//configure tris RGB lights (output)

    
    color_writetoaddr(0x00, 0x01); // write 1 to the PON bit in the device enable register
    
    //I2C_2_Master_Start();         //Start condition
	//I2C_2_Master_Write(0x52 | 0x00);     //7 bit address + Write mode
	//I2C_2_Master_Write(0xA0 | 0x16);    //command (auto-increment protocol transaction) + start at RED low register
	//I2C_2_Master_RepStart();			// start a repeated transmission
	//I2C_2_Master_Write(0x52 | 0x00);     //7 bit address + Write(0) mode
    //I2C_2_Master_Write()
    //I2C_2_Master_Stop(); //Stop condition
    
    TRISGbits.TRISG1=0; // red
    TRISAbits.TRISA4=0; // green
    TRISFbits.TRISF7=0; // blue
    TRISDbits.TRISD7=0; // LED on clicker 2 board
 
    LATDbits.LATD7=1; // LED on clicker 2 board
    
    LATGbits.LATG1=0; // red LED
    LATAbits.LATA4=0; // green LED
    //LATDbits.LATD7=1; // red LED
    LATFbits.LATF7=0; // red blue
    
    LATGbits.LATG1=1; // red LED
    __delay_ms(1000);
    LATAbits.LATA4=1; // green LED
    __delay_ms(1000);
    LATFbits.LATF7=1; // red blue
    __delay_ms(1000);
    
    
    while (1)
    {

    //readColours(&vals); //get RGB reading, store in variable RGB, located at vals
    //sprintf(buf,"red=%d green=%d blue=%d lum=%d\r\n",vals.R,vals.G,vals.B,vals.L); // send RGB reading to computer 


    
           
    readColours(&vals); //get RGB reading, store in variable RGB, located at vals
    colour_rel(&vals, &rel); //calculate relative RGB reading from RGB reading
    
    sprintf(buf,"red=%f green=%f blue=%f lum=%d\r\n",rel.R, rel.G,rel.B,vals.L); // send relative RGB readings to computer

    TxBufferedString(buf);
    //sendTxBuf();
    
  
    
        while (DataFlag){ 
            sendTxBuf();
        } 

//    }
//    
    }
}