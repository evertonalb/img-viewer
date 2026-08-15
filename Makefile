# Author: Everton Albuquerque de Oliveira
GCC = g++
PROG = test
INC = inc

build: main.o
	$(GCC) $< -o $(PROG)

main.o: main.cpp
	$(GCC) -I$(INC) -c $< -o $@

clean:
	rm *.o $(PROG)
