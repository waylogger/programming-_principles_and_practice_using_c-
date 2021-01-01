cpp="D:\\MS VS\\VC\\include\\Window.cpp" "D:\\MS VS\\VC\\include\\Graph.cpp" "D:\\MS VS\\VC\\include\\GUI.cpp"
Graph_h="D:\\MS VS\\VC\\include\\Graph.h"
Simple_window_h="D:\\MS VS\\VC\\include\\Simple_window.h"
std_lib_facilities_h="D:\\MS VS\\VC\\include\\std_lib_facilities.h"
Point_h="D:\\MS VS\\VC\\include\\Point.h"


OBS = 1.obj window.obj Graph.obj gui.obj
COPT= /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_UNICODE" /D "UNICODE" /MDd  /EHsc /c 
LOPT = /DYNAMICBASE "fltkd.lib" "fltkjpegd.lib" "fltkimagesd.lib" "kernel32.lib" "user32.lib" "gdi32.lib" "winspool.lib" "comdlg32.lib" "advapi32.lib" "shell32.lib" "ole32.lib" "oleaut32.lib" "uuid.lib" "odbc32.lib" "odbccp32.lib"

all : 
	cl 1.cpp $(cpp) $(COPT)
	link $(OBS) $(LOPT)
	

 
 