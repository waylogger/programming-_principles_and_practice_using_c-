long_adr="C:\\"Program Files (x86)"\\"Microsoft Visual Studio"\\2017\\Community\\VC\\Tools\\MSVC\\14.11.25503\\include\\"


cpp="$(long_adr)Window.cpp" \
"$(long_adr)Graph.cpp" \
"$(long_adr)GUI.cpp" \
"$(long_adr)MY\\CPP\\Extented_shape.cpp" \
"$(long_adr)MY\\CPP\\Nangle.cpp" \
"$(long_adr)MY\\CPP\\Basic_window.cpp" \
"$(long_adr)MY\\CPP\\Room.cpp" \
"$(long_adr)MY\\CPP\\Cave.cpp" \
"$(long_adr)MY\\CPP\\Wampus_window.cpp" 


OBS = 1.obj window.obj Graph.obj GUI.obj Extented_shape.obj Nangle.obj Basic_window.obj Room.obj Cave.obj Wampus_window.obj
COPT= /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_UNICODE" /D "UNICODE" /MDd  /EHsc /c
LOPT = /DYNAMICBASE "fltk.lib" "fltkjpeg.lib" "fltkimages.lib" "kernel32.lib" "user32.lib" "gdi32.lib" "winspool.lib" "comdlg32.lib" "advapi32.lib" "shell32.lib" "ole32.lib" "oleaut32.lib" "uuid.lib" "odbc32.lib" "odbccp32.lib" 


all : 
	cl  1.cpp  $(cpp) $(COPT)
	link $(OBS) $(LOPT) /NODEFAULTLIB:MSVCRT /SUBSYSTEM:WINDOWS
	

 
 