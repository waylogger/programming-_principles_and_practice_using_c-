.386
.model flat, stdcall
option casemap:none

include D:\masm32\include\windows.inc
include D:\masm32\include\kernel32.inc
include D:\masm32\include\user32.inc
includelib D:\masm32\lib\kernel32.lib
includelib D:\masm32\lib\user32.lib



.data
MessageBox proto hwnd:DWORD, lpText:DWORD, lpCaprion:DWORD, uType:DWORD
MsgBoxCaption db "Hello world!",0
MsgBoxText	db "Assembly is great",0
 
.code
start:
invoke MessageBox,NULL,addr MsgBoxText, addr MsgBoxCaption, MB_OK
invoke ExitProcess,NULL
end start