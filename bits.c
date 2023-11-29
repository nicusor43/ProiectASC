//
// Created by nicusor43 on 11/29/23.
//

#include "bits.h"

int currentbit = 0;
uint8_t bitbuffer = 0;

void writeBit(int bit, FILE* file){
    if(bit != 1 && bit != 0){
        fprintf(stderr, "Eroare: In loc de 1 sau 0 functia writeBit() a avut arg %d", bit);
    }

    bitbuffer <<= 1;
    bitbuffer |= bit;

    currentbit++;

    if(currentbit == 8){
        fwrite(&bitbuffer, 1, 1, file);
        currentbit = 0;
        bitbuffer = 0;
    }
}

void flushBits(FILE* file){
    while (currentbit){
        writeBit(0, file);
    }
}