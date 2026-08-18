#pragma once

#include "huffman.hpp"
#include <cstdio>

class Image{
public:
    HuffmanTable huffmanTable[4];
    char* filename;
    FILE* fp;

    Image(const char* filename);
    Image(const Image& other);

    Image& operator=(const Image& other);

    void read_dht_segment();
    
    // Reads in BITS list for Huffman table 'th'.
    void read_bits(int th);

    // Reads in HUFFVAL list for Huffman table 'th'.
    void read_huffval(int th);

    ~Image();
};
