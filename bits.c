//
// Created by nicusor43 on 11/29/23.
//

#include "bits.h"

// Code inspired (or maybe a bit more than that) by this
// StackOverflow thread: https://stackoverflow.com/questions/1856514/writing-files-in-bit-form-to-a-file-in-c

int current_bit = 0;
uint8_t bit_buffer = 0;

void writeBit(int bit, FILE *file) {

    if (bit != 1 && bit != 0) {
        fprintf(stderr, "Error: Instead of 1 or 0, writeBit() had argument %d", bit);
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

void writeInt(int number, FILE *file){
    // initial_string has to be initialized with 0s
    char reversed_string[33] = {};
    char char_bit[3];
    int length = 0;

    while (number != 0) {
        int bit = number % 2;

        snprintf(char_bit, 3,"%d", bit);
        strcat(reversed_string, char_bit);

        number /= 2;
        length++;
    }

    // Add 20 (the biggest int value?? for RISC-V instructions) - length 0s to the string
    for(int i = 0; i < 20 - length; i++){
        strcat(reversed_string, "0");
    }

    strrev(reversed_string);

    for (int i = 0; i < strlen(reversed_string); i++) {
        writeBit(reversed_string[i] - '0', file);
    }
}