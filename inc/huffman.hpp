// huffman.hpp
// Author: Everton Albuquerque de Oliveira
// Aug 8, 2026
#pragma once
#include <vector>

class HuffmanTable {
public:
    vector<int> huffsize;
    vector<unsigned char> huffcode;

    HuffmanTable(int numEntries){
        huffsize = vector<int>(numEntries);
        huffcode = vector<unsigned char>(numEntries);
    }
}


