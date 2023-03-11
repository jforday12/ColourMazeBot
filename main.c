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
#include "dc_motor.h"
#include "Memory.h"
#define _XTAL_FREQ 64000000 //note intrinsic _delay function is 62.5ns at 64,000,000Hz  


struct RGB_rel rel;
struct RGB vals;
volatile unsigned int move_count;  // variable to keep track of list index
void main(void) {
    initUSART4(); 
    Interrupts_init();
    color_click_init();
    I2C_2_Master_Init();
    initDCmotorsPWM(200);
    char buf[100];
    TRISGbits.TRISG1 = 0; // Set TRIS value for red LED (output)
    TRISAbits.TRISA4 = 0; // Set TRIS value for green LED (output)
    TRISFbits.TRISF7 = 0; // Set TRIS value for blue LED (output)
    TRISFbits.TRISF2 = 1; // Set Tris value for RF2 Button (input)
    ANSELFbits.ANSELF2=0;
    RED_LED=1; // sets RED LED on 
    GREEN_LED=1; // sets green LED on
    BLUE_LED=1; // sets Blue LED on
    

    //create structure for dc motors
    motorL.power=0; 						//zero power to start
    motorL.direction=1; 					//set default motor direction
    motorL.brakemode=1;						// brake mode (slow decay)
    motorL.posDutyHighByte=(unsigned char *)(&CCPR1H);  //store address of CCP1 duty high byte
    motorL.negDutyHighByte=(unsigned char *)(&CCPR2H);  //store address of CCP2 duty high byte
    motorL.PWMperiod=200; 			//store PWMperiod for motor (value of T2PR in this case)
    motorR.power=0; 						//zero power to start
    motorR.direction=1; 					//set default motor direction
    motorR.brakemode=1;						// brake mode (slow decay)
    motorR.posDutyHighByte=(unsigned char *)(&CCPR3H);  //store address of CCP1 duty high byte
    motorR.negDutyHighByte=(unsigned char *)(&CCPR4H);  //store address of CCP2 duty high byte
    motorR.PWMperiod=200; 			//store PWMperiod for motor (value of T2PR in this case)
    int consecuitive=0; // variable to register how many consecuitive readings there are
    int prev_colour =0; // variable to decide what the previous colour is 
    int run_flag=1;
    move_count=-1;
    
    while (RF3_button){
        __delay_ms(1000);
        turnRight45(&motorL, &motorR);
        turnRight45(&motorL, &motorR);
        turnRight45(&motorL, &motorR);
        turnRight45(&motorL, &motorR);
    }
        
    while (RF2_button);
    __delay_ms(1000);
    while (run_flag)
    {
        Forwardhalfblock(&motorL,&motorR);
        move_count++;
        WayBack[move_count]=0;
        //fullSpeedAhead(&motorL, &motorR);

        // read the colours and store it in the struct vals
        readColours(&vals);

        // obtain the relative RGB values and store it in the struct RGB_rel vals
        colour_rel(&vals, &rel);

        // if the clear value is greater than 2500 (value obtained from lowest clear value card which was blue) then it has hit a wall so detect what colour it sees
        if (vals.L>=2200){
            Forwardhalfblock(&motorL,&motorR);
            // stop the buggie
            stop(&motorL, &motorR);
            __delay_ms(200); 

//            int colour = Colour_decider(&vals, &rel);
//            sprintf(buf,"red=%f green=%f blue=%f lum=%d colour=%d \r\n",rel.R, rel.G,rel.B,vals.L,colour);
//            sendStringSerial4(buf);
            while (consecuitive<20){
                int colour = Colour_decider(&vals, &rel);
                if (colour==prev_colour){
                    consecuitive++;
                }
                else{
                    consecuitive=0;
                }
                prev_colour=colour;
                __delay_ms(50); 
            }
            consecuitive=0;
            //sprintf(buf,"red=%d green=%d blue=%d lum=%d colour=%d \r\n",vals.R, vals.G,vals.B,vals.L,prev_colour);
            sprintf(buf,"red=%f green=%f blue=%f lum=%d colour1=%d \r\n",rel.R, rel.G,rel.B,vals.L, prev_colour);
            sendStringSerial4(buf);
                //give move instruction based on returned colour
            if (prev_colour==1){ //red
                RedMove(&motorL, &motorR);
                move_count++;
                WayBack[move_count]=1;
            }
            else if(prev_colour==2){ //orange
                OrangeMove(&motorL, &motorR);
                move_count++;
                WayBack[move_count]=2;
            }
            else if(prev_colour==3){ //yellow
                YellowMove(&motorL, &motorR);
                move_count++;
                WayBack[move_count]=3;
            }
            else if(prev_colour==4){ //blue
                BlueMove(&motorL, &motorR);
                move_count++;
                WayBack[move_count]=4;
            }
            else if(prev_colour==5){ //green
                GreenMove(&motorL, &motorR);
                move_count++;
                WayBack[move_count]=5;
            }
            else if(prev_colour==6){ //light blue
                LightBlueMove(&motorL, &motorR);
                move_count++;
                WayBack[move_count]=6;
            }
            else if(prev_colour==7){ //pink
                PinkMove(&motorL, &motorR);
                move_count++;
                WayBack[move_count]=7;
            }
            else if (prev_colour==10){// undecided colour
                RetryMove(&motorL, &motorR);
            }
            else if (prev_colour==0){
                BlueMove(&motorL, &motorR);
                go_Home(WayBack);
                stop(&motorL, &motorR);
                run_flag=0;
            }



        }else{
            sprintf(buf,"red=%d green=%d blue=%d lum=%d \r\n",vals.R, vals.G,vals.B,vals.L);
            sendStringSerial4(buf);
        }


    }

}

    