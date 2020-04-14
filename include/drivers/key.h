#ifndef KEYBOARD_H
#define KEYBOARD_H
#include <types.h>


#define KEY_RELEASED 0x80


#define LSHIFT 	0x2A 

#define LSHIFT_P 	0x2A 
#define LSHIFT_R 	0xAA

#define RSHIFT 	0x36
#define CTRL   	0x1D
#define ALT    	0x38
#define DEL    	0x53


#define SPACE 0x39
#define ENTER 0x1C

#define ESC 0x1B

int keymap[57][2];




void handle_key(u8 scancode);
void init_keyboard();

char kb2(u8 code);





#endif