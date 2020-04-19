#include <types.h>
#include <stdlib.h>
#include <kernel/kprintf.h>
#include <kernel/debug.h>
#include <kernel/shell.h>
#include <kernel/multiboot.h>
#include <interrupt/idt.h>
#include <drivers/key.h>
#include <drivers/screen.h>
#include <drivers/pci.h>
#include <cpu/port.h>
#include <mm/mm.h>


void kmain(multiboot_info_t* mbd) {

	mbd= (multiboot_info_t*) (((u32*)mbd) + 0xC0000000);

	screen();
	

	clear_screen();
	kprint("MyOS");

	isr_install();
	asm volatile("sti");
	init_keyboard();
	init_shell();
	heap();

	dlog("mods - %d", mbd->mods_count);
	pci_init();
	u8 *b = kmalloc(100);
	pci_proc_dump(b);


	//count_memory();

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
