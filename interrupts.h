#ifndef _interrupts_H
#define _interrupts_H

#include "color.h"
#include "i2c.h"
#include <xc.h>

#define _XTAL_FREQ 64000000

void Interrupts_init(void);
void __interrupt(high_priority) HighISR();
extern volatile unsigned int move_count;




#endif
