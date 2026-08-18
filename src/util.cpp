// util.cpp
// Authur: Everton Albuquerque de Oliveira
// Aug 17, 2026
#include "util.hpp"

int next_byte(FILE* fp, unsigned char& byte){
    char buffer[2];
    if (fgets(buffer, 2, fp)){
        byte = buffer[0];
        return 1;
    } else return 0;
}

int next_two_bytes(FILE* fp, int& twoBytes){
    unsigned char byte;
    if (!next_byte(fp, byte)){
        return 0;
    }

    twoBytes = byte;

    if (!next_byte(fp, byte)){
        return 1;
    }

    twoBytes = (twoBytes << 8) | byte;
    return 2;
}
