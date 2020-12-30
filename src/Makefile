jabcodeReader/bin/jabcodeReader: jabcodeReader/Makefile jabcodeWriter/bin/jabcodeWriter
	make --directory=jabcodeReader/
jabcodeWriter/bin/jabcodeWriter: jabcodeWriter/Makefile jabcode/build/libjabcode.a
	make --directory=jabcodeWriter/
jabcode/build/libjabcode.a: jabcode/Makefile 
	make --directory=jabcode/
