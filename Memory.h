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




char WayBack [50];
int Time_forward[50];
extern volatile unsigned int move_count;
int run_flag=1;

void go_Home (char *WayBack, int *Time_forward);

#endif


