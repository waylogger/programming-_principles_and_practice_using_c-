


all:
	cl C:\\Programms\\25\\8\\1.cpp /c
	link C:\\Programms\\25\\8\\1.obj /DYNAMICBASE "user32.lib" "kernel32.lib" "GDI32.lib"