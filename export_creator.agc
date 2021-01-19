export=OpenToRead("export.txt")
header=OpenToWrite("export.h")

i=0

while not FileEOF(export)
	line$=ReadLine(export)
	
	if line$<>"" and line$<>" " then WriteLine(header,"void __JMP_API "+line$+"(void) { __asm jmp dword ptr [g_funcs+"+str(i)+"] }")
	i=i+4
endwhile

CloseFile(header)
CloseFile(export)
