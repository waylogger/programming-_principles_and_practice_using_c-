
address = "C:\Program Files (x86)\Microsoft Visual Studio\2017\Community\VC\Tools\MSVC\14.12.25827\include\FLTK"

OBS = 1.obj window.obj gui.obj graph.obj Text_analys.obj

cpp = $(address)\window.cpp $(address)\Gui.cpp $(address)\Graph.cpp $(address)\simple_window.cpp
COPT= /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_UNICODE" /D "UNICODE" /MDd  /EHsc /c 


LOPT = /NODEFAULTLIB:MSVCRT /DYNAMICBASE "fltk.lib" "fltkjpeg.lib" "fltkimages.lib" "kernel32.lib" "user32.lib" \
"gdi32.lib" "winspool.lib" "comdlg32.lib" "advapi32.lib" "shell32.lib" "ole32.lib" "oleaut32.lib" \
"uuid.lib" "odbc32.lib" "odbccp32.lib" 



all : 
	cl  1.cpp $(COPT)
	link $(OBS) $(LOPT)	/SUBSYSTEM:CONSOLE