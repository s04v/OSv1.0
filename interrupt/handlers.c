#include <kernel/debug.h>


void irq0_handler(void) {
          outb(0x20, 0x20); dlog("int!");

}
 
void irq1_handler(void) {
	    //outb(0x20, 0x20);
        dlog("int!");
}
 
void irq2_handler(void) {
          outb(0x20, 0x20); dlog("int!");
}
 
void irq3_handler(void) {
          outb(0x20, 0x20); dlog("int!");
}
 
void irq4_handler(void) {
          outb(0x20, 0x20); dlog("int!");
}
 
void irq5_handler(void) {
          outb(0x20, 0x20); dlog("int!");
}
 
void irq6_handler(void) {
          outb(0x20, 0x20); dlog("int!");
}
 
void irq7_handler(void) {
          outb(0x20, 0x20); dlog("int!");
}
 
void irq8_handler(void) {
          outb(0xA0, 0x20);
          outb(0x20, 0x20); dlog("int!");          
}
 
void irq9_handler(void) {
          outb(0xA0, 0x20);
          outb(0x20, 0x20); dlog("int!");
}
 
void irq10_handler(void) {
          outb(0xA0, 0x20);
          outb(0x20, 0x20); dlog("int!");
}
 
void irq11_handler(void) {
          outb(0xA0, 0x20);
          outb(0x20, 0x20); dlog("int!");
}
 
void irq12_handler(void) {
          outb(0xA0, 0x20);
          outb(0x20, 0x20); dlog("int!");
}
 
void irq13_handler(void) {
          outb(0xA0, 0x20);
          outb(0x20, 0x20); dlog("int!");
}
 
void irq14_handler(void) {
          outb(0xA0, 0x20);
          outb(0x20, 0x20); dlog("int!");
}
 
void irq15_handler(void) {
          outb(0xA0, 0x20);
          outb(0x20, 0x20); dlog("int!");
}