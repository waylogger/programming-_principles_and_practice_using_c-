#include<std_lib_facilities.h>
#include <windows.h>
#include <stdafx.h>

int main ()
{

int x =0;
int y =0;

while (true)
{
if (x<50) ++x;
SetCursorPos(x,y);
if (y<50) ++y;
SetCursorPos(x,y);
if (x>=50) --x;
SetCursorPos(x,y);
if (y>=50) --y;
SetCursorPos(x,y);
}



}