#ifndef _DISPLAY_
#define _DISPLAY_

#define VIDEO_ADDRESS 0xB8000 /* start of video memory*/
#define MAX_ROWS 25 /* width */
#define MAX_COLS 80 /* height */
#define WHITE_ON_BLACK 0x0f /* colors */
#define RED_ON_WHITE 0xf5

/*cursor position*/
int _X;
int _Y;

void screen();     /*main func to init screen(test mode) */

void kprint(char* s);   /*print string on screen*/

void put(char c);     /*put single char on sceen*/

//void clear();

//void pixel_at();

void set_coursor(int x,int y);

void clear_screen();

void move_cursor();  /* move cursor at _X,_Y position */

//void scroll();

//void kprintf(char* fmt,...);

//void kprintfn(char* fmt,...);


void backspace();
#endif
