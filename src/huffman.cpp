#include "huffman.hpp"

HuffmanTable::HuffmanTable() : tc(-1) {}
HuffmanTable::HuffmanTable(int Tc) : tc(Tc) {}

// Copy constructor
HuffmanTable::HuffmanTable(const HuffmanTable& that){
    this->huffsize = that.huffsize;
    this->huffcode = that.huffcode;
    this->n = that.n;
    this->tc = that.tc;
    for (int i = 1; i <= 16; i++)
        this->bits[i] = that.bits[i];
}

// Copy assignment
HuffmanTable& HuffmanTable::operator=(const HuffmanTable& that){
    this->huffsize = that.huffsize;
    this->huffcode = that.huffcode;
    this->n = that.n;
    this->tc = that.tc;
    for (int i = 1; i <= 16; i++)
        this->bits[i] = that.bits[i];
    return *this;
}

// Destructor
// Not implemented, might be needed in the future.
