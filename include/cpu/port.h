#ifndef _PORT_
#define _PORT_

#include <types.h>

u8 inb(u16 port);
void outb(u16 port, u8 data);


u16 inw(u16 port);
void outw(u32 port, u32 data);

#endif