#include "image.hpp"
#include "util.hpp"
#include <cstring>

Image::Image(const char* filename){
    this->filename = strdup(filename);
    this->fp = fopen(filename, "r");
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

void Image::read_dht_segment(){
    unsigned char byte;

    fprintf(stdout, "-------------------------\n");
    // Lh
    int lh = 0;
    next_byte(this->fp, byte);
    lh = byte<<8;
    next_byte(this->fp, byte);
    lh |= byte;
    fprintf(stdout, "Lh is %d\n", lh);

    // Tc and Th
    int tc, th;
    next_byte(this->fp, byte);
    tc = (byte & 0xf0) >> 4; // 4 MSB
    th = byte & 0x0f;        // 4 LSB
    fprintf(stdout, "Tc is %d and Th is %d\n", tc, th);

    // Instantiate HuffmanTable
    this->huffmanTable[th] = HuffmanTable(lh - 19, tc); // Lh - 16 (BITS) - 3 (Lh and Tc|Th)

    // Read in the BITS list
    for (int i = 1; i <= 16; i++){
        next_byte(this->fp, byte);
        huffmanTable[th].bits[i] = byte;
    }

    fprintf(stdout, "Printing BITS:\n");
    for (int i = 1; i <= 16; i++)
        fprintf(stdout, "Bits[%d] - %d\n", i, huffmanTable[th].bits[i]);

    // Read in HUFFVAL
    for (int i = 0; i < huffmanTable[th].n; i++){
        next_byte(this->fp, byte);
        huffmanTable[th].huffval.push_back(byte);
    }

    for (auto x : huffmanTable[th].huffval)
        fprintf(stdout, "%02x - ", x);

    fprintf(stdout, "\n-------------------------\n");
}

Image::~Image(){
    fclose(fp);
    free(filename);
}
