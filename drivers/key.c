#include <stdlib.h>
#include <interrupt/isr.h>
#include <kernel/debug.h>


static void keyboard_callback(registers_t regs) {
    pic_end(1);
    /* The PIC leaves us the scancode in port 0x60 */
    u8 scancode = inb(0x60);
    //char *sc_ascii;
    //int_to_ascii(scancode, sc_ascii);
    //handler_shell('Keyboard scancode: ");
    //print_s(sc_ascii);
    //handler_shell(', ");
    //print_letter(scancode);
    //handler_shell('\n");
    dlog("key %d", scancode);
}

void init_keyboard() {

   register_interrupt_handler(IRQ1, keyboard_callback); 
   irq_enable(1);
   //l_shift = 0;
}