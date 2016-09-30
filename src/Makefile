CC=g++ -std=c++11
#CFLAGS= -c -Wall
#WARNINGS = -Wall
GLFW=-lglfw3 -framework Cocoa -framework OpenGL -framework IOKit -framework CoreVideo
GLEW=-I/usr/include -L/usr/lib -lglew

all: LAVis

LAVis: main.o
	$(CC) main.o window_handler.o oc_shape.o oc_shape_rectangle2d.o mesh.o shader.o load_shaders.o -o LAVis $(GLFW) $(GLEW)

main.o: main.cpp window_handler.o oc_shape.o oc_shape_rectangle2d.o mesh.o shader.o load_shaders.o
	$(CC) -c main.cpp

window_handler.o: window_handler.cpp
	$(CC) -c window_handler.cpp

oc_shape.o: oc_shape.cpp
	$(CC) -c oc_shape.cpp

oc_shape_rectangle2d.o: oc_shape_rectangle2d.cpp
	$(CC) -c oc_shape_rectangle2d.cpp

mesh.o: mesh.cpp
	$(CC) -c mesh.cpp

shader.o: shader.cpp
	$(CC) -c shader.cpp

load_shaders.o: load_shaders.cpp
	$(CC) -c load_shaders.cpp

allinone:
	$(CC) -o LAVis main.cpp window_handler.cpp oc_shape.cpp oc_shape_rectangle2d.cpp $(GLFW) $(GLEW)
	#$(CC) -o LAVis main.cpp window_handler.cpp oc_shape.cpp oc_shape_rectangle2d.cpp $(GLFW)

run:
	./LAVis

clear:
	rm -rf *.o LAvis
