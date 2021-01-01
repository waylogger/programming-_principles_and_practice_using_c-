path 	= "D:\\MS VS\\VC\\include\\FLTK\\"


cl_opt 	= /D "WIN32" /D "_RELEASE" /D "_WINDOWS" /D "_UNICODE" /D "UNICODE" /MDd  /EHsc /c
base_list =  "fltk.lib" "fltkjpeg.lib" "fltkimages.lib" "kernel32.lib" "user32.lib" \
	"gdi32.lib" "winspool.lib" "comdlg32.lib" "advapi32.lib" "shell32.lib" "ole32.lib" "oleaut32.lib" \
	"uuid.lib" "odbc32.lib" "odbccp32.lib"


all:
	"D:\\MS VS\\VC\\bin\\cl" 1.cpp $(path)\\window.cpp $(path)\\gui.cpp $(path)\\graph.cpp $(cl_opt)
	"D:\\MS VS\\VC\\bin\\link" 1.obj window.obj gui.obj graph.obj \
	/NODEFAULTLIB:MSVCRT /SUBSYSTEM:"CONSOLE" /DYNAMICBASE $(base_list) 