
; example of simplified Windows programming using complex macro features

include 'D:\FASM\INCLUDE\win32ax.inc' ; you can simply switch between win32ax, win32wx, win64ax and win64wx here

.code

  start:
	invoke	MessageBox,HWND_DESKTOP,"Hello world",invoke GetCommandLine,MB_OK
	invoke	ExitProcess,0

.end start
