cc = gcc -g -lglfw -lstdc++ -I/usr/local/include -L/usr/local/lib -framework OpenGL
test: test.o window.o
	$(cc) -o test test.o window.o
test.o: test.cpp
	$(cc) -c test.cpp
window.o: window.cpp
	$(cc) -c window.cpp
