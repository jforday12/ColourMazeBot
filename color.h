#ifndef _color_H
#define _color_H

#include <xc.h>


#define _XTAL_FREQ 64000000 //note intrinsic _delay function is 62.5ns at 64,000,000Hz  


/********************************************//**
 *  Function to initialise the colour click module using I2C
 ***********************************************/
void color_click_init(void);

/********************************************//**
 *  Function to write to the colour click module
 *  address is the register within the colour click to write to
 *	value is the value that will be written to that address
 ***********************************************/
void color_writetoaddr(char address, char value);

/********************************************//**
 *  Function to read the red channel
 *	Returns a 16 bit ADC value representing colour intensity
 ***********************************************/
unsigned int color_read_Red(void);
unsigned int color_read_Blue(void);
unsigned int color_read_Green(void);
unsigned int color_read_lum(void);
struct RGB{
    int R;
    int G;
    int B;
    int L;
};


struct RGB_rel{
    float R;
    float G;
    float B;
};

int prev_colour =0; // variable to decide what the previous colour is 
int consecuitive=0; // variable to register how many consecuitive readings there are



void colour_rel(struct RGB *vals, struct RGB_rel *rel);

int Colour_decider(struct RGB *vals, struct RGB_rel *rel);
void readColours (struct RGB *vals);

int consecutive_read(struct RGB *vals, struct RGB_rel *rel);




#endif
