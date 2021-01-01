#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#pragma comment(lib, "User32.lib")
#include "errors.h"
 
void main (void)
{
    RECT lpRect;
    POINT pt;
    HWND hwnd;
    TCHAR buff[100];
    int X,Y;
    Sleep(5000);
    GetCursorPos(&pt);
        //�������� ���������� ����
    hwnd = WindowFromPoint(pt);
    if(!hwnd)
    {
        printf("Error FindWindow: %d\n",GetLastError());
        getch();
        exit(1);
    }
    //�������� ��� ������
    if(!GetClassName(hwnd,buff,100))
    {
        printf("Error GetClassName: %d\n", GetLastError());
        getch();
        exit(2);
    }
    //�������� ������������ ����
    if(!GetWindowRect(hwnd,&lpRect))
    {
        printf("Error GetWindowRect: %d\n", GetLastError());
        getch();
        exit(3);
    }
    printf("left(uX) = %d, top(uY) = %d\nright(lX) = %d, bottom(lY) = %d\n",lpRect.left, lpRect.top, lpRect.right, lpRect.bottom);
    //�������� ������� �������(���� ��� 2 ��� ���)
    if(!GetCursorPos(&pt))
    {
        printf("Error GetCursorPos: %d\n", GetLastError());
        getch();
        exit(4);
    }
    //��������� ������ ����
    X = lpRect.bottom - lpRect.top;
    Y = lpRect.right - lpRect.left;
    printf("Width = %d, height = %d\n", Y, X);
    //��������� ��������� �������
    pt.x = pt.x - lpRect.left;
    pt.y = pt.y - lpRect.top;
    printf("x = %d, y = %d\n",pt.x,pt.y);
    //�������� ����� ������ ���� �� �����������
    SendMessage(hwnd,WM_LBUTTONDOWN,MK_LBUTTON,MAKELONG(pt.x,pt.y));
    //��������� ����� ������ ���� �� �����������
    SendMessage(hwnd,WM_LBUTTONDOWN,0,MAKELONG(pt.x,pt.y));
    printf("success\n");
    getch();
} 