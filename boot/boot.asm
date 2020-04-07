bits 32

        ;multiboot spec
        align 4
        dd 0x1BADB002            ;magic
        dd 0x00                  ;flags
        dd - (0x1BADB002 + 0x00) ;checksum. m+f+c should be zero


section .page_tables, 
times 4096 db 0 

global boot_pdpt
boot_pdpt:
times 4096 db 0

section .text
global start
extern kmain	        ;kmain is defined in the c file



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



start:
        cli 			;block interrupts
        xor eax, eax
        mov ds, eax

        lgdt [gdt_descriptor]

        mov eax, cr0
        or eax, 1
        mov cr0, eax

        mov eax, DATA_SEG ; 5. update the segment registers
        mov ds, eax
        mov ss, eax
        mov es, eax
        mov fs, eax
        mov gs, eax
  ;mov eax, [boot_pdpt]
  ;sub eax, 0xc0000000
  ;mov cr3, eax
  ;mov esp, stack_space	;set stack pointer


  ;mov eax, cr4
  ;or eax, 0x60
  ;mov cr4, eax

  ;mov eax, cr0
  ;or eax, 0x80000000
  ;mov cr0, eax
  
  
  ;enable paging
        mov cr3, eax

        mov ebx, cr4        ; read current cr4
        or  ebx, 0x00000010 ; set PSE
        mov cr4, ebx        ; update cr4

        ;mov ebx, cr0        ; read current cr0
        ;or  ebx, 0x80000000 ; set PG
        ;mov cr0, ebx        ; update cr0

  

    call kmain
    hlt		 	;halt the CPU






section .bss
resb 8192		;8KB for stack
stack_space:

