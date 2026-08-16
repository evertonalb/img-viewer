# Author: Everton Albuquerque de Oliveira
GCC = g++
PROG = test
INC = inc
SRC = src
FLAGS = -c -g

build: main.o util.o image.o huffman.o
	$(GCC) $^ -o $(PROG)

main.o: main.cpp
	$(GCC) -I$(INC) $(FLAGS) $< -o $@

%.o: $(SRC)/%.cpp $(INC)/%.hpp
	$(GCC) -I$(INC) $(FLAGS) $< -o $@

clean:
	rm *.o $(PROG)
