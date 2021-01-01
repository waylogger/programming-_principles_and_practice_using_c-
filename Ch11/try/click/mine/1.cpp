#include <std_lib_facilities.h>
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#pragma comment(lib, "User32.lib")
#include "errors.h"

int main ()
{
	POINT pt;
	vector<POINT>vpt;
	while (true)
	{
		GetCursorPos(&pt);
		vpt.push_back(pt);
	}
	HWND hwnd = WindowFromPoint(pt);
	int i = 0;
	cin >> i;
	if (i==1) SendMessage(hwnd,WM_LBUTTONDBLCLK,0,MAKELONG(pt.x,pt.y));

	keep_window_open();
}