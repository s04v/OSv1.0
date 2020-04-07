#include <drivers/screen.h>
#include <stdlib.h>
#include <kernel/kprintf.h>
#include <kernel/debug.h>

void kmain(void) {

	screen();
	clear_screen();
	int a  = 61;
	kprintf("Hello World  %c true", a);	
	dlog("Hello debuger :)");

	return 0;
} 
