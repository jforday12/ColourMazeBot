#include "Memory.h"
#include "dc_motor.h"
#include "timers.h"
void go_Home (char *WayBack, int *Time_forward){
    int i;
    for (i = move_count; i >= 0; i--){
        TMR0H=0;
        TMR0L=0;
        unsigned int time_temp=TMR0L;
        int cur_time=TMR0H<<8;
        while (cur_time<Time_forward[i]){
            fullSpeedAhead(&motorL,&motorR);
            time_temp=TMR0L;
            cur_time=TMR0H<<8;
        }
            
        if (WayBack[i]==0){
            Forwardhalfblock(&motorL,&motorR);
        }
        else if (WayBack[i]==1){
            GreenMove(&motorL, &motorR); // opposite of red move
        }
        else if (WayBack[i]==2){
            LightBlueMove(&motorL, &motorR); // opposite of light blue move]
        }
        else if (WayBack[i]==3){
            ReverseYellow(&motorL, &motorR); // opposite of yellow move
        }
        else if (WayBack[i]==4){
            BlueMove(&motorL, &motorR); // 180 degrees same either way
        }
        else if (WayBack[i]==5){
            RedMove(&motorL, &motorR); //opposite of green move
        }
        else if (WayBack[i]==6){
            OrangeMove(&motorL, &motorR); // opposite of lightblue move
        }
        else if (WayBack[i]==7){
            ReversePink(&motorL, &motorR);
        }


  } 
}

