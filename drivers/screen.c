#include <types.h>
#include <drivers/screen.h>


void screen() {   
    _X = 0;
 	_Y = 0;
  	//scroll_f= 0;
}


void put(char c) {
    char *vid = (char*) VIDEO_ADDRESS;
	
    if(_Y>= MAX_ROWS)
    {
        scroll();
        _Y = MAX_ROWS-1;
        //move_cursor();
        return;
    }
    
    if (c == '\n')
   	{
       	_X = 0;
       	_Y++;
		return;
	}

	vid[_X + _Y*MAX_COLS*2] = c;
	vid[_X + 1 + _Y*MAX_COLS*2] = 7;
	_X += 2;
    //move_cursor();
}

void clear_screen(){
	set_cursor(0,0);
	for (u32 i = 0; i < MAX_COLS * MAX_ROWS*2; ++i)
	{
		put(' ');
	}
	set_cursor(0,0);
    //move_cursor();
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


//todo move_cursor