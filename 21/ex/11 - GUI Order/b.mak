
address = "D:\MS VS\VC\include\FLTK"
my_address = "D:\MS VS\VC\include\My"

OBS = 1.obj window.obj gui.obj graph.obj order_window.obj tools.obj Address.obj Date.obj name.obj purchase.obj order.obj

cpp = $(my_address)\order.cpp $(address)\window.cpp $(address)\Gui.cpp $(address)\Graph.cpp $(address)\simple_window.cpp $(my_address)\order_window.cpp \
$(my_address)\tools.cpp  $(my_address)\Address.cpp $(my_address)\Date.cpp  \
$(my_address)\name.cpp $(my_address)\purchase.cpp  $(my_address)\formated_order_window.cpp

COPT= /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_UNICODE" /D "UNICODE" /MDd  /EHsc /c


LOPT = /DYNAMICBASE "fltk.lib" "fltkjpeg.lib" "fltkimages.lib" "kernel32.lib" "user32.lib" \
"gdi32.lib" "winspool.lib" "comdlg32.lib" "advapi32.lib" "shell32.lib" "ole32.lib" "oleaut32.lib" \
"uuid.lib" "odbc32.lib" "odbccp32.lib" 

all : 
	cl  $(cpp) $(COPT)
				

 
 