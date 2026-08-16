#include "util.hpp"

int next_byte(FILE* fp, unsigned char& byte){
    char buffer[2];
    if (fgets(buffer, 2, fp)){
        byte = buffer[0];
        return 1;
    } else return 0;
}
