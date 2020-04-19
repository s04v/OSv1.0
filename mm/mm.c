#include <types.h>
#include <kernel/kprintf.h>
#include <mm/mm.h>


#define HEADER 4
#define HEAP_SIZE 1024*1024

extern int end_of_kernel_image;

static u8* heap_ = &end_of_kernel_image;

static u16 IN_USE;


#define db(a) dlog(a)

void print_list()
{
    for(int i = 0; i < IN_USE; i++)
    {
        kprintf("ptr [%x]. size[%d].\n", LIST[i].ptr,LIST[i].size);
    }
}

void LOG()
{
    kprintf("OUR LIST\n");
    for(int i = 0; i < IN_USE; i++)
    {
        kprintf("LIST[%d].ptr = %x\n",i, LIST[i].ptr);
        kprintf("LIST[%d].size = %x\n",i, LIST[i].size);
        kprintf("\n");
    }
}
void heap() {
    if(LIST[0].ptr == NULL && LIST[0].size == 0)
    {
        LIST[0].ptr = heap_;
        LIST[0].size = HEAP_SIZE;
        IN_USE++;
    }
}
void* kmalloc(size_t size) {
    
    size += HEADER;

    entity_t* best = LIST;

    for (u32 i = 0; i < IN_USE; i++)
    {
        if(LIST[i].size >= size && LIST[i].size < best->size)
        {
            best = &LIST[i];
        }
    }


    u8* start = best->ptr;
    u8* user_ptr = start + HEADER;

    *start = size;

    best->ptr += size;
    best->size -= size; 

   /// kprintfn("best entity...");
   // kprintfn("ptr [%x], size [%d]", best->ptr, best->size);

    return user_ptr;
}
int in_u()
{
    return IN_USE;
}

/*void* kmalloc(size_t size)
{
    if(size <= HEAP_SIZE)
        return -1;

    size += HEADER;

    entity_t* e = new_entity(size);
    
    u8* start = e->ptr;
    u8* user_ptr = start + HEADER;

    *start = size;

    e->ptr += size;
    e->size -= size; 


  


    return (void*)user_ptr;
}*/

void kfree(void* ptr)
{
    u8* start = (u8*)ptr - HEADER;
    size_t size = (u8)*((u8*)ptr-HEADER);
    int f = 0;
    for (u32 i = 0; i <= IN_USE; i++)
    {
        dlog("LSIT ptr - %d, start - %d, size -  %d\n",LIST[i].ptr, &(*start), (u8)*((u8*)ptr-HEADER));
        if((LIST[i].ptr - size) == start)
        {
            LIST[i].ptr = start;
            LIST[i].size += size;
            break;
        }
        else{

            f = 1;
        }
    }
    
    if(f)
    {
        LIST[IN_USE].ptr = &(*start);
        LIST[IN_USE].size = (u8)*((u8*)ptr-HEADER);
        IN_USE++;
    }

}


/*Test*/

size_t count_memory()
{

	unsigned int * mem = &end_of_kernel_image;
    dlog("First address - [%x]\n", mem);
	int count = 0;
	do {
		unsigned int val = *mem;
		*mem = 0xBE0DEAD;
		unsigned int val1 = *mem;
		*mem = val;
		if (!(val1 == 0xBE0DEAD))
			break;
		count++;    
		mem = (void*)((size_t)mem + 1);
	} while (1);

    dlog("Last address - [%x]\n", mem);
	return count;
}
