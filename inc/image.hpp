#pragma once

#include "huffman.hpp"
#include <cstdio>

class Image{
public:
    HuffmanTable huffmanTable[4];
    unsigned int q[4][64]; // Four quantization tables
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

    void read_dqt_segment();

    // Reads in a quantization table into destination tq
    void read_qtable(int pq, int tq);

    ~Image();
};
