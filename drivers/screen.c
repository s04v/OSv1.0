#include <types.h>	
#include <drivers/screen.h>

u8 scroll_f;

void screen() {   
    _X = 0;
 	_Y = 0;
  	scroll_f= 0;
}


void put(char c) {
    char *vid = (char*) VIDEO_ADDRESS;
	
    if(_Y>= MAX_ROWS)
    {
        //scroll();
        _Y = MAX_COLS-1;
        move_cursor();
        return;
    }


    
    if (c == '\n')
   	{
       	_X = 0;
       	_Y++;
	    move_cursor();

		return;
	}

	vid[_X + _Y*MAX_COLS*2] = c;
	vid[_X + 1 + _Y*MAX_COLS*2] = 7;
	_X += 2;
	
	if(_X > MAX_COLS*2)
	{
		_Y++;
		_X = 0;
	}
    move_cursor();
}

void clear_screen(){
	set_cursor(0,0);
	for (u32 i = 0; i < MAX_COLS * MAX_ROWS*2; ++i)
	{
		put(' ');
	}
	set_cursor(0,0);
    move_cursor();
}



void set_cursor(int x,int y)
{
	_X = x;
	_Y = y;
}


void scroll()
{
  	memcpy((char*)(0xB8000 + MAX_COLS*2), (char*)0xB8000, MAX_COLS*MAX_ROWS*2);
}


void move_cursor()
{
   // The screen is 80 characters wide...
   unsigned short cursorLocation = _Y * 80 + _X/2;
   outb(0x3D4, 14);                  // Tell the VGA board we are setting the high cursor byte.
   outb(0x3D5, cursorLocation >> 8); // Send the high cursor byte.
   outb(0x3D4, 15);                  // Tell the VGA board we are setting the low cursor byte.
   outb(0x3D5, cursorLocation);      // Send the low cursor byte.
}

//todo move_cursor