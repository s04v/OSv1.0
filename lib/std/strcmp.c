#include <types.h>


int strcmp(char *s1, char *s2){

    u32 i;
    char *c1, *c2;
    for (c1=s1, c2=s2;(*c1)!='\0'; c1++,c2++){
        if((*c1) - (*c2) != 0)
            return 0; // if not equals
    }
    
    return 1; // if equals
}