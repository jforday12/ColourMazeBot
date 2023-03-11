#include "Memory.h"
#include "dc_motor.h"
void go_Home (char *WayBack){
    int i;
    for (i = move_count; i >= 0; i--){
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
