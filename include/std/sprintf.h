#ifndef _SPRINTF_
#define _SPRINTF_

#include <stdarg.h>
#include <types.h>

int sprintf(char *buf, const char *fmt, va_list args);

int pr(const char* fmt, ...);
#endif