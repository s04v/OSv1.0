#ifndef _MM_
#define _MM_

#include <types.h>


#define HEADER 4
#define HEAP_SIZE 256*2


typedef struct entity {
    u8* ptr;
    int size;
} entity_t;

entity_t LIST[40];

void LOG();

void* new_entity(size_t size);

void heap();

void* kmalloc(size_t size);

void print_list();

void kfree(void* ptr);  

size_t count_memory();

#endif