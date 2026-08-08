// main.cpp
// Author: Everton Albuquerque de Oliveira
#include <iostream>
#include <cstdio>

// Saves next byte of fp into "byte".
// Returns 0 if the file ended and 1 otherwise.
int next_byte(FILE* fp, unsigned char& byte);

int main(int argc, char* argv[]){
    FILE* fp = fopen("examples/colored_8x8.jpg", "r");

    // Detect markers
    unsigned char byte;
    while (next_byte(fp, byte)){
        if (byte == 0xff){ // potential marker
            next_byte(fp, byte);
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

int next_byte(FILE* fp, unsigned char& byte){
    char buffer[2];
    if (fgets(buffer, 2, fp)){
        byte = buffer[0];
        return 1;
    } else return 0;
}
