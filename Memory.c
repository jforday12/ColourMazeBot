#include "Memory.h"
#include "dc_motor.h"
#include "timers.h"
void go_Home (char *WayBack, int *Time_forward){
    int i;
        for (i = move_count; i >= 0; i--){
 

            timed_forward(&motorL, &motorR,Time_forward[i]);


            if (WayBack[i-1]==1){
                reverseDetect(&motorL, &motorR);
                GreenMove(&motorL, &motorR); // opposite of red move
            }
            else if (WayBack[i-1]==2){
                reverseDetect(&motorL, &motorR);
                LightBlueMove(&motorL, &motorR); // opposite of light blue move]
            }
            else if (WayBack[i-1]==3){
                reverseDetect(&motorL, &motorR);
                ReverseYellow(&motorL, &motorR); // opposite of yellow move
            }
            else if (WayBack[i-1]==4){
                reverseDetect(&motorL, &motorR);
                BlueMove(&motorL, &motorR); // 180 degrees same either way
            }
            else if (WayBack[i-1]==5){
                reverseDetect(&motorL, &motorR);
                RedMove(&motorL, &motorR); //opposite of green move
            }
            else if (WayBack[i-1]==6){
                reverseDetect(&motorL, &motorR);
                OrangeMove(&motorL, &motorR); // opposite of lightblue move
            }
            else if (WayBack[i-1]==7){
                reverseDetect(&motorL, &motorR);
                ReversePink(&motorL, &motorR);
            }


      }
        
    }

