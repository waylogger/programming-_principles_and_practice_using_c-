.386
.model	flat, stdcall
option	casemap:none
include	D:\masm32\include\windows.inc
include	D:\masm32\include\user32.inc
include	D:\masm32\include\kernel32.inc
includelib D:\masm32\lib\kernel32.lib
includelib D:\masm32\lib\user32.lib


WinMain proto :DWORD,:DWORD,:DWORD,:DWORD

.DATA
ClassName db	"SimpleWinClass",0
AppName db	"Out first window",0
 
.DATA?
hInstance HINSTANCE ?  
CommandLine LPSTR ?
.code
start:
invoke GetModuleHandle, NULL
mov hInstance,eax
mov hInstance,eax
invoke GetCommandLine 
mov CommandLine,eax
invoke WinMain,hInstance,NULL,CommandLine,SW_SHOWDEFAULT
invoke ExitProcess,0  

WinMain proc hInst:HINSTANCE,hPrevInst:HINSTANCE,CmdLine:LPSTR,CmdShow:DWORD

LOCAL wc:WNDCLASSEX
LOCAL msg:MSG
LOCAL hwnd:HWND

mov	wc.cbSize,SIZEOF WNDCLASSEX
mov	wc.style,CS_HREDRAW or CS_VREDRAW
mov	wc.lpfnWndProc, OFFSET WndProc 
mov	wc.cbClsExtra,NULL
mov	wc.cbWndExtra,NULL
push	hInstance
pop	wc.hInstance
mov wc.hbrBackground, COLOR_WINDOW+1

mov	wc.lpszMenuName,NULL
mov	wc.lpszClassName,OFFSET	ClassName
invoke LoadIcon,NULL,IDI_APPLICATION
mov	wc.hIcon,eax
mov	wc.hIconSm,eax
invoke	LoadCursor,NULL,IDC_ARROW
mov	wc.hCursor,eax
invoke	RegisterClassEx, addr wc
invoke	CreateWindowEx,NULL, ADDR ClassName, \
						ADDR AppName, \
						WS_OVERLAPPEDWINDOW, \
						CW_USEDEFAULT, \
						CW_USEDEFAULT, \
						CW_USEDEFAULT, \
						CW_USEDEFAULT, \
						NULL, \
						NULL, \
						hInst, \
						NULL
mov	hwnd,eax
invoke ShowWindow, hwnd, CmdShow
invoke	UpdateWindow, hwnd

.WHILE TRUE
invoke	GetMessage, ADDR msg, NULL,0,0
.BREAK .IF (!eax)
	invoke	TranslateMessage, ADDR msg
	invoke	DispatchMessage, ADDR msg
.ENDW
mov	eax,msg.wParam
ret


WinMain endp

WndProc proc hWnd:HWND, uMsg:UINT, wParam:WPARAM, lParam:LPARAM

.IF	uMsg==WM_DESTROY

invoke	PostQuitMessage,NULL
.ELSE
	invoke DefWindowProc,hWnd,uMsg,wParam,lParam
	ret
	.ENDIF
	xor	eax,eax
	ret

WndProc endp

end start



































