#include <drivers/screen.h>
#include <kernel/shell.h>
#include <kernel/kprintf.h>
#include <kernel/debug.h>
#include <drivers/key.h>

int X;
int Y;


int last_c;  


/*
 * TODO:
 * fix line() function
 * fix '9' output
 */
void init_shell()
{
	//print_s("--- Shell ---\n");
	//line();
	X = _X;
	Y = _Y;
	//buf_i = 0;
	last_c = 0;
}

void shell_print(char code) {

	if(code == SPACE){
		put(' ');
		X++;
	}
	else if(code == ENTER)
	{
		X = 0;
		Y++;
		//kprintf("\n");
		line();
	}else
	{
		//dlog("code = %x", code);
		put(code);
		X++;
	}
		
	//dlog("X = %d, Y = %d",_X,_Y);

}

void line() {

	kprintf("\nroot@coronaos:~> ");
	X = _X;
	Y = _Y;
	//buf_i = 0;

}

