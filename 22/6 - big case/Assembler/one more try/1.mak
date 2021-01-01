all:
	D:\masm32\bin\ml.exe -Zi /c /coff  "D:\Programms\22\7 - big case\C\Assembler\one more try\1.asm" \
	/Fo "D:\Programms\22\7 - big case\C\Assembler\one more try\1.obj"
	D:\masm32\bin\link.exe /OPT:REF "D:\Programms\22\7 - big case\C\Assembler\one more try\1.obj" /SUBSYSTEM:CONSOLE