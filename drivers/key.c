#include <stdlib.h>
#include <interrupt/isr.h>
#include <kernel/debug.h>
#include <drivers/key.h>
#include <kernel/shell.h>
#include <drivers/screen.h>
#include <kernel/kprintf.h>

static void keyboard_callback(registers_t regs) {
    u8 scancode = inb(0x60);
    char *sc_ascii = convert(scancode, 10);
    dlog("%d",scancode);

    print_letter(scancode);
    

}

void init_keyboard() {

   register_interrupt_handler(IRQ1, keyboard_callback); 
   irq_enable(1);
   //l_shift = 0;
}

char print_letter(u8 code) {
    static u8 l_shift = 0;
    static u8 l_alt = 0;
    static u8 l_ctrl = 0;

    char key;

   

    if(code == LSHIFT_P)
    {   
        l_shift = 1;
        return -1;
    }
    
    if(code == LSHIFT_R)
    {
         l_shift = 0;
         return -1;
    }   

    if(code <= 52) {
        
        if(l_shift)
            put(keymap[code][1]);
        else
            put(keymap[code][0]);
    }

    
    
}


int keymap[][2] = {
	/* 0 */		{0, 0},      {ESC, 0},
	/* 2 */		{'1', '!'},  {'2', '@'},
	/* 4 */		{'3', '#'},  {'4', '$'},
	/* 6 */		{'5', '%'},  {'6', '^'},
	/* 8 */		{'7', '&'},  {'8', '*'},
	/* 10 */	{'9', '('},  {'0', ')'},
	/* 12 */	{'-', '_'},  {'=', '+'},
	/* 14 */	{'\b', '\b'},{'\t', 0},
	/* 16 */	{'q', 'Q'},  {'w', 'W'},
	/* 18 */	{'e', 'E'},  {'r', 'R'},
	/* 20 */	{'t', 'T'},  {'y', 'Y'},
	/* 22 */	{'u', 'U'},  {'i', 'I'},
	/* 24 */	{'o', 'O'},  {'p', 'P'},
	/* 26 */	{'�', '`'},  {'[', '{'},
	/* 28 */	{'\n', 0},   {'/', '?'},
	/* 30 */	{'a', 'A'},  {'s', 'S'},
	/* 32 */	{'d', 'D'},  {'f', 'F'},
	/* 34 */	{'g', 'G'},  {'h', 'H'},
	/* 36 */	{'j', 'J'},  {'k', 'K'},
	/* 38 */	{'l', 'L'},  {'�', '�'},
	/* 40 */	{'~', '^'},  {'\'', '"'},
	/* 42 */	{LSHIFT, 0}, {']', '}'},
	/* 44 */	{'z', 'Z'},  {'x', 'X'},
	/* 46 */	{'c', 'C'},  {'v', 'V'},
	/* 48 */	{'b', 'B'},  {'n', 'N'},
	/* 50 */	{'m', 'M'},  {',', '<'},
	/* 52 */	{'.', '>'},  {';', ':'},
};