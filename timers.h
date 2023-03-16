#ifndef _timers_H
#define _timers_H

#include <xc.h>

#define _XTAL_FREQ 64000000

void Timer0_init(void); // initialize timer
void getTMR0val(void); // read count from timer
void delayed_ms(int time); // custom delay function
#endif