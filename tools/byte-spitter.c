// byte-spitter.c
// Reads in a file and spits out all its bytes in order.
// Author: Everton Albuquerque de Oliveira
// Aug 7, 2026

#include <stdio.h>

// Prints out to stdout every byte of the fp file.
void spit_bytes(FILE* fp){
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
}

int main(int argc, char* argv[]){
    // Only allow for only one cmd-line argument
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

    spit_bytes(fp);

    fprintf(stdout, "\n");
    fclose(fp);
    return 0;
}
