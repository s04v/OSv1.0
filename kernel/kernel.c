#include <types.h>
#include <drivers/screen.h>
#include <stdlib.h>
#include <kernel/kprintf.h>
#include <kernel/debug.h>
#include <interrupt/idt.h>
#include <drivers/key.h>
#include <kernel/shell.h>

#define PIC1 0x20
#define PIC2 0xA0

#define ICW1 0x11
#define ICW4 0x01

extern int text_start;
extern int text_end;

void p();

void kmain(int addr) {


	screen();

	clear_screen();
	
	kprint("CoronaOS");	
	isr_install();
	asm volatile("sti");

	init_keyboard();

	init_shell();
	shell_print(1);

	print_letter(0x20);
	p();


	//init_timer(50);
	//init_keyboard();
	
	return 0;
} 


void p()
{
	put('0');
};
