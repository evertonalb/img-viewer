#include "image.hpp"
#include "util.hpp"
#include <cstdlib>
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

    // Lh
    int lh = 0;

    if (!next_byte(this->fp, byte)){
        fprintf(stderr, "File corrupted.\n");
        exit(EXIT_FAILURE);
    }

    lh = byte<<8;

    if (!next_byte(this->fp, byte)){
        fprintf(stderr, "File corrupted.\n");
        exit(EXIT_FAILURE);
    }

    lh |= byte;

    int byte_count = 2;
    while (byte_count < lh){
        // Tc and Th
        int tc, th;

        if (!next_byte(this->fp, byte)){
            fprintf(stderr, "File corrupted.\n");
            exit(EXIT_FAILURE);
        }

        byte_count++;
        tc = (byte & 0xf0) >> 4; // 4 MSB
        th = byte & 0x0f;        // 4 LSB

        // Instantiate HuffmanTable
        this->huffmanTable[th] = HuffmanTable(tc);

        // Read in the BITS list
        read_bits(th);
        byte_count += 16;

        // Read in HUFFVAL
        read_huffval(th);
        byte_count += huffmanTable[th].n;
    }
}

void Image::read_bits(int th){
    unsigned char byte;
    int sz = 0;
    for (int i = 1; i <= 16; i++){

        if (!next_byte(this->fp, byte)){
            fprintf(stderr, "File corrupted.\n");
            exit(EXIT_FAILURE);
        }

        huffmanTable[th].bits[i] = byte;
        sz += byte;
    }
    huffmanTable[th].n = sz;
}

void Image::read_huffval(int th){
    unsigned char byte;
    for (int i = 0; i < huffmanTable[th].n; i++){

        if (!next_byte(this->fp, byte)){
            fprintf(stderr, "File corrupted.\n");
            exit(EXIT_FAILURE);
        }

        huffmanTable[th].huffval.push_back(byte);
    }
}

Image::~Image(){
    fclose(fp);
    free(filename);
}
