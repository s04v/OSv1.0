bits 32

        ;multiboot spec
        align 4
        dd 0x1BADB002            ;magic
        dd 0x00                  ;flags
        dd - (0x1BADB002 + 0x00) ;checksum. m+f+c should be zero


global page_directory


section .text
global start
extern kmain	        ;kmain is defined in the c file


;global page_directory
; extern page_directory

start:
        cli 			;block interrupts
        xor eax, eax
        mov ds, eax
        mov esp, stack_space


        mov eax, 0x0
        mov ebx, 0x0


        .fill_table0:
            mov    ecx, ebx
            or     ecx, 3              ; Present; Supervisor;
            mov    [page_table0+eax*4], ecx
            add    ebx, 4096
            inc    eax
            cmp    eax, 1024            ; 1024 frames = 4MB
            je     .end0
            jmp    .fill_table0
        .end0:


        mov     eax, 0x0
        mov     ebx, 0x100000
        .fill_table:
            mov    ecx, ebx
            or     ecx, 3              ; Present; Supervisor; R/W;
            mov    [page_table768+eax*4], ecx
            add    ebx, 4096
            inc    eax
            cmp    eax, 1024
            je     .end
            jmp    .fill_table
        .end:

        mov     eax, page_table0
        ;and     eax, 0xFFFFF000
        or      eax, 3
        mov     ebx, page_directory
        mov     [ebx], eax


        mov     eax, page_table768
        ;and     eax, 0xFFFFF000
        or      eax, 3
        mov     ebx, page_directory
        mov     [ebx+768*4], eax ; 0xC0000000 

        ;and     eax, 0xFFFFF000

        ; or      eax, 3

        ;mov     cr0, eax
        lgdt [gdt_descriptor]
        mov eax, cr0
        or al, 1
        mov cr0, eax


        mov     eax, page_directory
        mov     cr3, eax
        mov     eax, cr0
        or      eax, 0x80000001
        mov cr0,eax

        mov eax, DATA_SEG ; 5. update the segment registers
        mov ds, eax
        mov ss, eax
        mov es, eax
        mov fs, eax
        mov gs, eax
  
    mov ebx, [page_directory]
    push ebx
    call kmain
    hlt		 	;halt the CPU



section .data

gdt_start: ; don't remove the labels, they're needed to compute sizes and jumps
    ; the GDT starts with a null 8-byte
    dd 0x0 ; 4 byte
    dd 0x0 ; 4 byte

; GDT for code segment. base = 0x00000000, length = 0xfffff
; for flags, refer to os-dev.pdf document, page 36
gdt_code: 
    dw 0xffff    ; segment length, bits 0-15
    dw 0x0       ; segment base, bits 0-15
    db 0x0       ; segment base, bits 16-23
    db 10011010b ; flags (8 bits)
    db 11001111b ; flags (4 bits) + segment length, bits 16-19
    db 0x0       ; segment base, bits 24-31

; GDT for data segment. base and length identical to code segment
; some flags changed, again, refer to os-dev.pdf
gdt_data:
    dw 0xffff
    dw 0x0
    db 0x0
    db 10010010b
    db 11001111b
    db 0x0

gdt_end:

; GDT descriptor
gdt_descriptor:
    dw gdt_end - gdt_start - 1 ; size (16 bit), always one less of its true size
    dd gdt_start ; address (32 bit)

; define some constants for later use
CODE_SEG equ gdt_code - gdt_start
DATA_SEG equ gdt_data - gdt_start

align 1024
section .bss

page_directory:
    resb  0x1000
page_table0:
    resb  0x1000
page_table768:
    resb  0x1000



resb 8192		;8KB for stack
stack_space:

