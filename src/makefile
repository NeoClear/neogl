cc = gcc -g -lstdc++ -lglfw -I/usr/local/include -L/usr/local/lib -framework OpenGL
ar = ar cr
obj = main.o window.o group.o nl_namespace.o nl_call_main.o widget.o button.o slide.o
lib = window.o group.o nl_namespace.o nl_call_main.o widget.o button.o slide.o

all: $(obj)
	$(cc) -o main $(obj)
	$(ar) pack.a $(lib)

main.o: main.cpp
	$(cc) -c main.cpp
window.o: window.cpp
	$(cc) -c window.cpp
group.o: group.cpp
	$(cc) -c group.cpp
nl_namespace.o: nl_namespace.cpp
	$(cc) -c nl_namespace.cpp
nl_call_main.o: nl_call_main.cpp
	$(cc) -c nl_call_main.cpp
widget.o: widget.cpp
	$(cc) -c widget.cpp
button.o: button.cpp
	$(cc) -c button.cpp
slide.o: slide.cpp
	$(cc) -c slide.cpp

.PHONY: clean run

clean:
	-rm -rf *.o main *.a

run:
	./main
