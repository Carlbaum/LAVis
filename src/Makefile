CC=g++
CFLAGS=-c -Wall
GLFW=-lglfw3 -framework Cocoa -framework OpenGL -framework IOKit -framework CoreVideo

all: LAVis

LAVis: main.o
	$(CC) main.o window_handler.o -o LAVis $(GLFW)

main.o: main.cpp window_handler.o
	$(CC) -c main.cpp

window_handler.o: window_handler.cpp
	$(CC) -c window_handler.cpp

allinone:
	$(CC) -o LAVis main.cpp window_handler.cpp $(GLFW)

run:
	./LAVis

clear:
	rm -rf *.o LAvis
