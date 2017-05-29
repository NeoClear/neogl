obj = main.o
cc = gcc -g -lstdc++ -lglfw -I/usr/local/include -L/usr/local/lib -framework OpenGL -I ../../src ../../src/pack.a

all: $(obj)
	$(cc) -o main $(obj)

main.o: main.cpp
	$(cc) -c main.cpp

.PHONY: clean run

clean:
	-rm *.o main

run:
	./main
