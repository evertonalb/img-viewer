#include "huffman.hpp"

HuffmanTable::HuffmanTable(int numEntries){
    huffsize.resize(numEntries);
    huffcode.resize(numEntries);
    for (int i = 1; i <= 16; i++) bits[i] = 0;
}
