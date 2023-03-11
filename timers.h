#ifndef _timers_H
#define _timers_H

#include <xc.h>

#define _XTAL_FREQ 64000000

void Timer0_init(void);
void getTMR0val(void);
void delayed_ms(int time);
extern volatile unsigned int move_count;
#endif
