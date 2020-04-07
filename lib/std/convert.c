#include <types.h>

char* convert(unsigned int num, int base)
{
    static char Rep[] = "0123456789ABCDEF";
    static char buffer[50];

    char* ptr;

    ptr = &buffer[49];
    *ptr = '\0';
   
    do {
        *--ptr = Rep[num%base];
        num/= base;
    }while(num != 0);

    if(base == 16)
    {
        *--ptr= 'x';
        *--ptr= '0';

    }
    return (ptr);
}