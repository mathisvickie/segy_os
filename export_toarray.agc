export=OpenToRead("export.txt")
array=OpenToWrite("array.h")

WriteLine(array,"char* g_exports[] = {")

while not FileEOF(export)
	line$=ReadLine(export)
	
	if line$<>"" and line$<>" " then WriteLine(array,chr(9)+chr(34)+line$+chr(34)+",")
endwhile

WriteLine(array,"};")

CloseFile(array)
CloseFile(export)
