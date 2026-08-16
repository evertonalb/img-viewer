#pragma once

#include <cstdio>

// Saves next byte of fp into "byte".
// Returns 0 if the file ended and 1 otherwise.
int next_byte(FILE* fp, unsigned char& byte);
