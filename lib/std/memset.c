#include <types.h>


void memset(void* src, u8 value, u32 n) {
    for(u32 i = 0; i < n; i++)
        ((u8*)src)[i] = value; 
}