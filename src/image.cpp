#include "image.hpp"
#include <cstring>

Image::Image(const char* filename){
    fp = fopen(filename, "r");
    this->filename = strdup(filename);
}

// Copy constructor
Image::Image(const Image& that){
    for (int i = 0; i < 4; i++)
        this->huffmanTable[i] = that.huffmanTable[i];
    this->fp = fopen(filename, "r");
    this->filename = strdup(that.filename);
}

// Copy assignment
Image& Image::operator=(const Image& that){
    for (int i = 0; i < 4; i++)
        this->huffmanTable[i] = that.huffmanTable[i];
    this->filename = strdup(that.filename);
    return *this;
}

Image::~Image(){
    fclose(fp);
    free(this->filename);
}
