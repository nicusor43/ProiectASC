//
// Created by nicusor43 on 11/29/23.
//

#include "bits.h"

int current_bit = 0;
uint8_t bit_buffer = 0;

void writeBit(int bit, FILE *file) {
    if (bit != 1 && bit != 0) {
        fprintf(stderr, "Eroare: In loc de 1 sau 0 functia writeBit() a avut arg %d", bit);
    }

    bit_buffer <<= 1;
    bit_buffer |= bit;

    current_bit++;

    if (current_bit == 8) {
        fwrite(&bit_buffer, 1, 1, file);
        current_bit = 0;
        bit_buffer = 0;
    }
}

void flushBits(FILE *file) {
    while (current_bit) {
        writeBit(0, file);
    }
}