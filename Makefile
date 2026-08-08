# Author: Everton Albuquerque de Oliveira
GCC = g++
PROG = test

build: main.o
	$(GCC) $< -o $(PROG)

main.o: main.cpp
	$(GCC) -c $< -o $@

clean:
	rm *.o
