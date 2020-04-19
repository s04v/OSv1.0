C_SOURCES = $(wildcard \
	kernel/*.c \
	drivers/*.c \
	lib/*.c \
	lib/std/*.c \
	cpu/*.c \
	mm/*.c \
	shell/*.c \
	keyboard/*.c \
	interrupt/*.c \
	pci/*.c \
	fs/*.c )


HEADERS = $(wirdcard include/*.h include/std/*.h include/drivers/*.h include/kernel/*.h)


OBJ = ${C_SOURCES:.c=.o boot/boot2.o  interrupt/interrupts.o}

INCLUDES = \
	-Iinclude/


FLAGS = -fno-pic -mno-sse -nostdlib -nostdinc -fno-builtin -nostartfiles -nodefaultlibs -fno-stack-protector -ffreestanding -std=gnu99 -nostdinc




run: kernel.bin
	qemu-system-i386 -hda hard.img -vga virtio -serial stdio -m 152 -kernel kernel.bin
	#-monitor stdio
	#
	make clean

db: kernel.bin
	qemu-system-x86_64  -serial stdio -m 152 -kernel kernel.bin -hda hard.img
	make clean


kernel.bin: kernel/kernel.o  ${OBJ}
	ld -m elf_i386 -T kern.ld -o $@  $^


%.o: %.c ${HEADERS}
	gcc  -w ${INCLUDES} ${FLAGS} -m32 -c   $< -o $@
%.o: %.asm
	nasm -f elf32 $< -o $@

clean:
	@rm */*.o
	@rm */*/*.o
	@rm kernel.bin
