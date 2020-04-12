bits 32




    align 4
multiboot:
        ;multiboot spec
        dd 0x1BADB002            ;magic
        dd 0x00                  ;flags
        dd - (0x1BADB002 + 0x00) ;checksum. m+f+c should be zero



section .text
global start
extern kmain

start:
    cli
    mov esp, stack
    push esp
    push ebx
    call kmain
    hlt
    

section .bss
    resb 8192
stack: