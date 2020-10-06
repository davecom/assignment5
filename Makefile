CC = cl
FLAGS = /std:c++17 /WX /EHsc
OBJECTS = PPlot.obj SVGPainter.obj test.obj main.obj 

assignment5: $(OBJECTS)
	$(CC) /Fe"assignment5" $(OBJECTS)

PPlot.obj: lib\PPlot.cpp lib\PPlot.h
	$(CC) $(FLAGS) /c lib\PPlot.cpp

SVGPainter.obj: lib\SVGPainter.cpp lib\SVGPainter.h
	$(CC) $(FLAGS) /c lib\SVGPainter.cpp

test.obj: src\test.cpp src\sort.h
	$(CC) $(FLAGS) /I lib\ -c src\test.cpp

main.obj: src\main.cpp src\sort.h
	$(CC) $(FLAGS) /I lib\ -c src\main.cpp

clean:
	del assignment5.exe *.obj *.svg
