// main.cpp
// Author: Everton Albuquerque de Oliveira
// Aug 16, 2026
#include <cstdio>
#include <vector>
#include "util.hpp"
#include "image.hpp"
#include "huffman.hpp"

int main(int argc, char* argv[]){

    Image img("examples/colored_8x8.jpg");

    // Detect markers
    unsigned char byte;
    while (next_byte(img.fp, byte)){
        if (byte == 0xff){ // potential marker
            next_byte(img.fp, byte);
            if (byte != 0x00){
                fprintf(stdout, "Spotted marker 0xff%02x.\n", byte);
                switch (byte){
                case 0xd8:
                    fprintf(stdout, "Start-of-image marker.\n");
                    break;
                case 0xd9:
                    fprintf(stdout, "End-of-image marker.\n");
                    break;
                case 0xda:
                    fprintf(stdout, "Start-of-scan marker.\n");
                    break;
                case 0xc4:
                    fprintf(stdout, "Define Huffman Table marker.\n");
                    // TODO: Call function to read segment
                    break;
                default:
                    fprintf(stdout, "This marker has not been implemented yet.\n");
                    break;
                }
            }
        }
    }

    fprintf(stdout, "End of image!\n");
    return 0;
}
