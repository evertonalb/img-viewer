// huffman.hpp
// Author: Everton Albuquerque de Oliveira
// Aug 8, 2026
#pragma once
#include <vector>

// Class used to store huffman table info
// TODO: Implement function that fill up HUFFSIZE and HUFFCODE
class HuffmanTable {
public:
    vector<int> huffsize;
    vector<unsigned char> huffcode;
    unsigned short int bits[17];

    HuffmanTable(int numEntries);
}

/** The DHT segment consists of:
 * DHT marker (0xffc4)
 * Lh: two bytes, total length of the segment (including Lh, excluding
 *  DHT)
 * 
 * Next byte is:
 *  Tc: upper 4 bits - table class, either 0 for DC table or 1 for AC table
 *   (components of the DCT)
 *  Th: Huffman table destination identifier, one of four (0 to 3)
 *
 * BITS list
 * The ith next byte (Li): number of symbols of length i.
 *
 * HUFFVAL
 * Finally, the values (symbols) Vi,j
