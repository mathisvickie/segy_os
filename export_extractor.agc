decompile=OpenToRead("decompile.h")
export=OpenToWrite("export.txt")

while not FileEOF(decompile)
	line$=ReadLine(decompile)
	
	if line$<>"" and line$<>" "
		
		line$=GetStringToken(line$,"(",1)
		line$=GetStringToken(line$," ",CountStringTokens(line$," "))
		
		if CountStringTokens(line$,"@")>1 then line$=GetStringToken(line$,"@",1)
		
		if Left(line$,4)<>"FUN_" and line$<>"entry" then WriteLine(export,line$)
	endif
endwhile

CloseFile(export)
CloseFile(decompile)
