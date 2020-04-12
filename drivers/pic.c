#include <drivers/pic.h>
#include <cpu/port.h>
#include <types.h>

static u16 ocw1 = 0xFFFB;

void irq_enable(u8 irq)
{
    ocw1 &= (u16)~((1 << irq));

    if (irq < 8)
		outb(0x21, (u8)(ocw1 & 0xFF));
	else
		outb(0xA1, (u8)(ocw1 >> 8));
}



void pic_end(u8 irq)
{
  if ( irq > 7)
    outb(0xA0, 0x20);

  outb(0x20, 0x20);
}

