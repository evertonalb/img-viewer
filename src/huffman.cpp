#include "huffman.hpp"

HuffmanTable::HuffmanTable(){
    HuffmanTable(0);
}

HuffmanTable::HuffmanTable(int numEntries) : n(numEntries) {
    huffsize.resize(numEntries);
    huffcode.resize(numEntries);
    for (int i = 1; i <= 16; i++) bits[i] = 0;
}

// Copy constructor
HuffmanTable::HuffmanTable(const HuffmanTable& that){
    this->huffsize = that.huffsize;
    this->huffcode = that.huffcode;
    for (int i = 1; i <= 16; i++)
        this->bits[i] = that.bits[i];
}

// Copy assignment
HuffmanTable& HuffmanTable::operator=(const HuffmanTable& that){
    this->huffsize = that.huffsize;
    this->huffcode = that.huffcode;
    for (int i = 1; i <= 16; i++)
        this->bits[i] = that.bits[i];
    return *this;
}

// Destructor
// Not implemented, might be needed in the future.
