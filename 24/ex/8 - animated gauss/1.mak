graph = "D:\\MS VS\\VC\\include\\FLTK\\graph.cpp"
window = "D:\\MS VS\\VC\\include\\FLTK\\window.cpp"
gui = "D:\\MS VS\\VC\\include\\FLTK\\Gui.cpp"

ftlk_libs =  "fltk.lib" "fltkjpeg.lib" "fltkimages.lib" "kernel32.lib" "user32.lib" \
	"gdi32.lib" 	\
	"winspool.lib"	\
	"comdlg32.lib" 	\
	"advapi32.lib" 	\
	"shell32.lib" 	\
	"ole32.lib" 	\
	"oleaut32.lib"	"uuid.lib" 		"odbc32.lib"		"odbccp32.lib" 
all:
	cl 1.cpp  /c /EHsc  /D "WIN32" /MDd
	link 1.obj graph.obj gui.obj window.obj my_gauss.obj /NODEFAULTLIB:MSVCRT /DYNAMICBASE $(ftlk_libs) /SUBSYSTEM:WINDOWS