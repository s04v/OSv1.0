#include <stdarg.h>
#include <drivers/screen.h>
#include <std/sprintf.h>


void kprint(char* str) {
    int in = 0;
	while(str[in])
		put(str[in++]);
}

void kprintf(char* fmt,...) {
    char buf[512];
    va_list args;
    int printed;

    va_start(args, fmt);
    printed = sprintf(buf, fmt, args);
    va_end(args);
    
    kprint(buf);
}

void kprintfn(char* fmt,...) {
    char buf[512];
    va_list args;
    int printed;

    va_start(args, fmt);
    printed = sprintf(buf, fmt, args);
    va_end(args);
    
    kprint(buf);
	put('\n');
}