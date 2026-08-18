// util.hpp
// Authur: Everton Albuquerque de Oliveira
// Aug 17, 2026
#pragma once

#include <cstdio>

// Saves next byte of fp into "byte".
// Returns 0 if the file ended and 1 otherwise.
int next_byte(FILE* fp, unsigned char& byte);

// Saves next two bytes of fp into twoBytes
// Returns number of bytes read.
int next_two_bytes(FILE* fp, int& twoBytes);
