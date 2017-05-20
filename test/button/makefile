obj = main.o
cc = gcc -g -lstdc++ -lglfw -I/usr/local/include -L/usr/local/lib -framework OpenGL -I ~/neoclear/neogl/src ~/neoclear/neogl/src/pack.a

all: $(obj)
	$(cc) -o main $(obj)

main.o: main.cpp
	$(cc) -c main.cpp

.PHONY: clean run

clean:
	-rm *.o main

run:
	./main
