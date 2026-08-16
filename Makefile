# Author: Everton Albuquerque de Oliveira
GCC = g++
PROG = test
INC = inc
SRC = src

build: main.o util.o
	$(GCC) $^ -o $(PROG)

main.o: main.cpp
	$(GCC) -I$(INC) -c $< -o $@

util.o: $(SRC)/util.cpp $(INC)/util.hpp
	$(GCC) -I$(INC) -c $< -o $@

clean:
	rm *.o $(PROG)
