#ifndef KEYBOARD_H
#define KEYBOARD_H

#include <types.h>

char l_shift;



void handle_key(u8 scancode);
void init_keyboard();

#endif