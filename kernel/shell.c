#include <drivers/screen.h>
#include <kernel/shell.h>
#include <kernel/kprintf.h>
#include <kernel/debug.h>


int X;
int Y;


int last_c;  

void init_shell()
{
	// print_s("--- Shell ---\n");
	//line();
	X = _X;
	Y = _Y;
	//buf_i = 0;
	last_c = 0;
}

void shell_print(char code)
{
    kprintf("---shell---");

}

