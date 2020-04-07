#include <cpu/serial.h>
#include <stdarg.h>

void dprint(char* str)
{
    int in = 0;
	while(str[in])
		write_serial(str[in++]);
}


void dlog(char* fmt,...)
{
    char buf[512];
    va_list args;
    int printed;

    va_start(args, fmt);
    printed = sprintf(buf, fmt, args);
    va_end(args);
    
    dprint(buf);
    write_serial('\n');
    write_serial('\r');
    va_end(args);
}