address = "D:\MS VS\VC\include\\FLTK"

cpplist = $(address)\\window.cpp $(address)\\gui.cpp $(address)\\Graph.cpp Language_stream.cpp history_guard.cpp
compil_options = /c /D "WIN32"  /D "_WINDOWS" /D "_RELEASE" /EHsc /D "_UNICODE" /D "UNICODE" /MDd




linkers_options = /SUBSYSTEM:CONSOLE /NODEFAULTLIB:MSVCRT /DYNAMICBASE "fltk.lib" "fltkjpeg.lib" "fltkimages.lib" "kernel32.lib" "user32.lib" \
				"gdi32.lib" "winspool.lib" "comdlg32.lib" "advapi32.lib" "shell32.lib" \
				"ole32.lib" "oleaut32.lib" "uuid.lib" "odbc32.lib" "odbccp32.lib" 

linkers_list = window.obj graph.obj gui.obj history_guard.obj Language_stream.obj 





all :
		cl  $(compil_options) $(cpplist) 1.cpp
		link $(linkers_options) 1.obj  $(linkers_list) 

