all:
	D:\masm32\bin\ml.exe /c /coff /Cp  "D:\Programms\22\7 - big case\C\Assembler\window\1.asm" /Fo \
	"D:\Programms\22\7 - big case\C\Assembler\window\1.obj"
	D:\masm32\bin\link.exe /LIBPATH:D:\masm32\lib\ \
	"D:\Programms\22\7 - big case\C\Assembler\window\1.obj" /SUBSYSTEM:WINDOWS \
	