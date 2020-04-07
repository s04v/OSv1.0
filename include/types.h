#ifndef TYPES_H
#define TYPES_H

typedef unsigned char 	    u8;
typedef unsigned short 	    u16;
typedef unsigned int 	    u32;
typedef unsigned long long 	u64;


typedef signed char 	    s8;
typedef signed short 	    s16;
typedef signed int 		    s32;
typedef signed long long	s64;

typedef unsigned char u_char;

typedef unsigned int size_t;

#define NULL 0
#define true 1
#define false 0


#define low_16(address) (u16)((address) & 0xFFFF)
#define high_16(address) (u16)(((address) >> 16) & 0xFFFF)

#endif