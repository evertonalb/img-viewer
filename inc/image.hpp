#pragma once

#include "huffman.hpp"
#include <cstdio>
#include <cstdlib>

class Image{
public:
    HuffmanTable huffmanTable[4];
    char* filename;
    FILE* fp;

    Image(const char* filename);
    
    Image(const Image& other);

    Image& operator=(const Image& other);
    ~Image();
};
