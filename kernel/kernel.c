#include <types.h>
#include <drivers/screen.h>
#include <stdlib.h>
#include <kernel/kprintf.h>
#include <kernel/debug.h>
#include <interrupt/idt.h>
#include <drivers/key.h>


#define PIC1 0x20
#define PIC2 0xA0

#define ICW1 0x11
#define ICW4 0x01

extern int text_start;
extern int text_end;



void kmain(int addr) {


	screen();

	clear_screen();
	
	kprintf("Hello WorldHello WorldHello WorldHello WorldHello WorldHello WorldHello WorldHello WorldHello WorldHello WorldHello WorldHello WorldHello WorldHello WorldHello WorldHello WorldHello WorldHello WorldHello World");	
	kprintf("Hello WorldHello WorldHello WorldHello WorldHello WorldHello WorldHello WorldHello WorldHello WorldHello WorldHello WorldHello WorldHello WorldHello WorldHello WorldHello WorldHello WorldHello WorldHello World");	
	kprintf("Hello WorldHello WorldHello WorldHello WorldHello WorldHello WorldHello WorldHello WorldHello WorldHello WorldHello WorldHello WorldHello WorldHello WorldHello WorldHello WorldHello WorldHello WorldHello World");	
	kprintf("Hello WorldHello WorldHello WorldHello WorldHello WorldHello WorldHello WorldHello WorldHello WorldHello WorldHello WorldHello WorldHello WorldHello WorldHello WorldHello WorldHello WorldHello WorldHello World");	
	
	isr_install();
	asm volatile("sti");
	init_keyboard();

	//init_timer(50);
	//init_keyboard();
	
	return 0;
} 
