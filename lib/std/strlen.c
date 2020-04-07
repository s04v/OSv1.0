#include <types.h>

u32 strlen(char* str) {
    u32 i = 0;
    while(*str++)
        i++;

    return i;
}