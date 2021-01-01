all:
	D:\masm32\bin\ml.exe /c /coff /Cp  "D:\Programms\22\7 - big case\C\Assembler\try\1.asm" \
	/Fo "D:\Programms\22\7 - big case\C\Assembler\try\1.obj"
	D:\masm32\bin\link.exe "D:\Programms\22\7 - big case\C\Assembler\try\1.obj" /SUBSYSTEM:CONSOLE /LIBPATH:D:\masm32\lib