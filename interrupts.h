#ifndef _interrupts_H
#define _interrupts_H

#include "color.h"
#include "i2c.h"
#include <xc.h>

#define _XTAL_FREQ 64000000

void Interrupts_init(void);
void __interrupt(high_priority) HighISR();

void colour_interrupt_init(void);
void clear_int(void);

extern volatile char DataFlag;
extern volatile char ColourFlag;

int low_threshold=0;
int high_threshold=1000;

#endif
