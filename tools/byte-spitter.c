// byte-spitter.c
// Reads in a file and spits out all its bytes in order.
// Author: Everton Albuquerque de Oliveira
// Aug 6, 2026

#include <stdio.h>

int main(int argc, char* argv[]){
    // Only allow for one cmd-line argument
    if (argc < 2 || argc > 2){
        fprintf(stderr, "Usage: %s [FILENAME]\n", argv[0]);
        return 1;
    }

    FILE* fp;
    fp = fopen(argv[1], "r");
    if (!fp){
        fprintf(stderr, "File not found.\n");
        return 1;
    }

    unsigned char buffer[2]; // unsigned so that the MSB doesn't get extended
    int c = 20; // counter for where to put the new line
    while (fgets(buffer, 2, fp)){
        if (c == 0){
            fprintf(stdout, "\n");
            c = 20;
        }
        fprintf(stdout, "%02x ", buffer[0]); // print out one byte
        c--;
    }
    fprintf(stdout, "\n");
    return 0;
}
