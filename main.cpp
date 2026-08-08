// main.cpp
// Author: Everton Albuquerque de Oliveira
#include <iostream>
#include <cstdio>

// Saves next byte of fp into "byte".
// Returns 0 if the file ended and 1 otherwise.
int next_byte(FILE* fp, unsigned char& byte);

int main(int argc, char* argv[]){
    FILE* fp = fopen("huff_simple0.jpg", "r");

    unsigned char byte;
    while (next_byte(fp, byte)){
        if (byte == 0xff){
            next_byte(fp, byte);
            if (byte != 0x00)
                fprintf(stdout, "Spotted marker 0xff%02x.\n", byte);
        }
    }

    fprintf(stdout, "End of image!\n");
    return 0;
}

int next_byte(FILE* fp, unsigned char& byte){
    char buffer[2];
    if (fgets(buffer, 2, fp)){
        byte = buffer[0];
        return 1;
    } else return 0;
}
