#include <types.h>

void memcpy(void* dest, void* src, u32 size) {
    for(u32 i = 0; i < size; i++)
        ((u8*)dest)[i] = ((u8*)src)[i];
}