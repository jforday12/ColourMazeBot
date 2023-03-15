#include <xc.h>
#include "colour_move.h"
#include "dc_motor.h"
#include "Memory.h"
#include "serial.h"
#include "color.h"

void colour_move (int recognized_colour) 
{

    //give move instruction based on returned colour
    if (recognized_colour==1){ //red
        RedMove(&motorL, &motorR); 
        TMR0H=0; // reset timer values
        TMR0L=0;
        WayBack[move_count]=1;
        lost_count=0;
    }
    else if(recognized_colour==2){ //orange
        OrangeMove(&motorL, &motorR);
        TMR0H=0; // reset timer values
        TMR0L=0;
        WayBack[move_count]=2;
        lost_count=0;
    }
    else if(recognized_colour==3){ //yellow
        YellowMove(&motorL, &motorR);
        TMR0H=0; // reset timer values
        TMR0L=0;
        WayBack[move_count]=3;
        lost_count=0;
    }
    else if(recognized_colour==4){ //blue
        BlueMove(&motorL, &motorR);
        TMR0H=0; // reset timer values
        TMR0L=0;
        WayBack[move_count]=4;
        lost_count=0;
    }
    else if(recognized_colour==5){ //green
        GreenMove(&motorL, &motorR);
        TMR0H=0; // reset timer values
        TMR0L=0;
        WayBack[move_count]=5;
        lost_count=0;
    }
    else if(recognized_colour==6){ //light blue
        LightBlueMove(&motorL, &motorR);
        TMR0H=0; // reset timer values
        TMR0L=0;
        WayBack[move_count]=6;
        lost_count=0;
    }
    else if(recognized_colour==7){ //pink
        PinkMove(&motorL, &motorR);
        TMR0H=0; // reset timer values
        TMR0L=0;
        WayBack[move_count]=7;
        lost_count=0;
    }
    else if (recognized_colour==10){// undecided colour
        lost_count++;
        if (lost_count>=3){
            go_Home(WayBack, Time_forward);
        }
        else{
            RetryMove(&motorL, &motorR);
            TMR0H=0; // reset timer values
            TMR0L=0;
        }
    }
    else if (recognized_colour==0){
        go_Home(WayBack, Time_forward);
    }
}
