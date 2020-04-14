#include <types.h>
#include <stdlib.h>
#include <kernel/kprintf.h>
#include <kernel/debug.h>
#include <kernel/shell.h>
#include <interrupt/idt.h>
#include <drivers/key.h>
#include <drivers/screen.h>
#include <cpu/port.h>

#define PIC1 0x20
#define PIC2 0xA0

#define ICW1 0x11
#define ICW4 0x01

extern int text_start;
extern int text_end;

void kmain(int addr) {


	screen();

	clear_screen();
	kprint("CoronaOS");

	isr_install();
	asm volatile("sti");
	init_keyboard();
	init_shell();


	//init_timer();
	//init_shell();
	//shell_print(1);

	//char *vid = (char*) VIDEO_ADDRESS;
	//dlog("memkernel - %c",*vid);


	//init_timer(50);
	//init_keyboard();
	
	return 0;
} 


void p()
{
	put('0');
};
