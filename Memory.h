/* 
 * File:   Memory.h
 * Author: jford
 *
 * Created on March 10, 2023, 7:45 PM
 */

#ifndef MEMORY_H
#define	MEMORY_H

#include <xc.h>

#define _XTAL_FREQ 64000000 //note intrinsic _delay function is 62.5ns at 64,000,000Hz  


<<<<<<< Updated upstream
char WayBack [250];
volatile unsigned int move_count;
=======
char WayBack [50];
int Time_forward[50];
extern volatile unsigned int move_count;
>>>>>>> Stashed changes

void go_Home (char *WayBack, int *Time_forward);

#endif


