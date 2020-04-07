
#include <stdarg.h>
#include <types.h>
#include <stdlib.h>

int sprintf(char *buf, const char *fmt, va_list args) {
    char* str;
    int i;
    char* s;

    for(str = buf; *fmt; ++fmt) {
        if (*fmt != '%') {
            *str++ = *fmt;
            continue;
        }

        ++fmt;

        switch(*fmt) {
            case 'd':
                i = va_arg(args,int);
                s =  convert(i, 10);
                for(;*s;s++)
                    *str++ = *s;
                break;
            case 'c':
                i = va_arg(args, char);
                *str++ = (char)i;
                break;
            case 'x':
                i = va_arg(args,int);
                s =  convert(i, 16);
                for(;*s;s++)
                    *str++ = *s;
                break;
        default:
            break;
        }
    }

    *str = '\0';
	return str-buf;
}

//int pr(const char* fmt, ...);