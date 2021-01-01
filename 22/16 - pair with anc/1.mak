address = "C:\Program Files (x86)\Microsoft Visual Studio\2017\Community\VC\Tools\MSVC\14.12.25827\include\FLTK"

cpp_list = $(address)\window.cpp $(address)\gui.cpp $(address)\graph.cpp
obj_list = window.obj gui.obj graph.obj

cpp_opt = /D "WIN32" /D "_RELEASE" /D "_WINDOWS" /D "_UNICODE" /D "UNICODE" /MDd  /EHsc /c

base_list = /DYNAMICBASE "fltk.lib" "fltkjpeg.lib" "fltkimages.lib" "kernel32.lib" "user32.lib" \
	"gdi32.lib" "winspool.lib" "comdlg32.lib" "advapi32.lib" "shell32.lib" "ole32.lib" "oleaut32.lib" \
	"uuid.lib" "odbc32.lib" "odbccp32.lib"
	
lnk_opt = /NODEFAULTLIB:MSVCRT /SUBSYSTEM:"CONSOLE"

all:
	cl 1.cpp  $(cpp_opt)
	link  1.obj $(obj_list) /DYNAMICBASE $(base_list) $(lnk_opt)
	