#ifndef _PIC_
#define _PIC_

#include <types.h>

#define IRQ_BASE  0x20

void pic(void);
void irq_enable(u8 irq);
void pic_end(u8 irq);




#endif