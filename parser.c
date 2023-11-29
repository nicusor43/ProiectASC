//
// Created by nicusor43 on 11/24/23.
//

#include "parser.h"
#include "helpers.h"
#include "bits.h"

#define NUMBER_OF_INSTRUCTIONS 21

typedef struct {
    char *key;
    char *value;
} dictionary;

/* DICTIONARY WITH ALL OF THE INSTRUCTIONS THAT *COULD* BE USED
hashtable dictionar_huffman[] = {
    { "ADD","010"}, 
    { "SUB","011010"}, 
    { "XOR","0"}, 
    { "OR","0"}, 
    { "AND","000100"}, 
    { "SLL","0"}, 
    { "SRL","0"}, 
    { "SRA","0"}, 
    { "SLT","0"}, 
    { "SLTU","0"}, 
    { "ADDI","11"}, 
    { "XORI","0"}, 
    { "ORI","0"}, 
    { "ANDI","0"}, 
    { "SLLI","10100"}, 
    { "SRLI","0"}, 
    { "SRAI","011011"}, 
    { "SLTI","0"}, 
    { "SLTIU","0"}, 
    { "LB","0111"}, 
    { "LH","0"}, 
    { "LW","1011"}, 
    { "LBU","0"}, 
    { "LHU","0"}, 
    { "SB","1001"}, 
    { "SH","0"}, 
    { "SW","0"}, 
    { "BEQ","0"}, 
    { "BNE","0"}, 
    { "BLT","0"}, 
    { "BGE","0011"}, 
    { "BLTU","0"}, 
    { "BGEU","0"}, 
    { "JAL","101011"}, 
    { "JALR","0"}, 
    { "LUI","0"}, 
    { "AUIPC","0"}, 
    { "ECALL","0"}, 
    { "EBREAK","0"}, 
    { "BEQZ","0010"}, 
    { "BNEZ","101010"}, 
    { "FLD","01100"}, 
    { "FSW","10000"}, 
    { "BGT","100011"}, 
    { "CALL","00011"}, 
    { "FMV.S.X","100010"}, 
    { "FMUL.S","0001011"}, 
    { "FADD.S","0001010"}, 
    { "SD","0000"}
};
*/

// Dictionary of huffman codes for each RISC-V
// instruction, as calculated by Iulia.
dictionary dictionar_huffman[NUMBER_OF_INSTRUCTIONS] = {
    { "add","010"},
    { "sub","011010"},
    { "and","000100"},
    { "addi","11"},
    { "slli","10100"},
    { "srai","011011"},
    { "lb","0111"},
    { "lw","1011"},
    { "sb","1001"},
    { "bge","0011"},
    { "jal","101011"},
    { "beqz","0010"},
    { "bnez","101010"},
    { "fld","01100"},
    { "fsw","10000"},
    { "bgt","100011"},
    { "call","00011"},
    { "fmv.s.x","100010"},
    { "fmul.s","0001011"},
    { "fadd.s","0001010"},
    { "sd","0000"}
};


// Function that parses the file and returns something? TODO
void parseFile(char *inputfile, char *outputfile){
    char str[64]; 

    FILE* input = fopen(inputfile, "r");
    FILE* output = fopen(outputfile, "wb");

    /*
    while (fgets(s, sizeof(s), fp) != NULL) {
        printf("Linia %d: %s \n", ++linecount, s);
    }
    */

    while (fscanf(input, "%63s", str) == 1){
        // fputs(checkInstruction(str), output);

        // In cazul in care str este o instructiune de RISC-V,
        // chechInstruction va returna un string diferit, deci
        // vrem sa-l scriem
        if(checkInstruction(str) != str){
            char * traducere = checkInstruction(str);

            uint64_t bit_instruction = strtol(traducere, &traducere, 10);

            // Test what bit_instruction becomes
            printf("%lu \n", bit_instruction);

            while(bit_instruction != 0){
                writeBit(bit_instruction % 10, output);
                bit_instruction /= 10;
            }
        }

        // fwrite(checkInstruction(str), sizeof(char), sizeof(checkInstruction(str)), output);
    }

    fclose(input);

    flushBits(output);
    fclose(output);
}

// Function which returns the huffman code equivalent
// to a RISC-V instruction, if it is one, as calculated by Iulia
char* checkInstruction(char *instruction){
    for(int i = 0; i < NUMBER_OF_INSTRUCTIONS; i++){
        if(strcmp(dictionar_huffman[i].key, instruction) == 0){
            return dictionar_huffman[i].value;
        }
    }
    return instruction;
}

void printHelp() {
    printf("Usage: ./assembler [OPTIONS] [INPUT FILE] [OUTPUT FILE]\n");
    printf("Options:\n");
}
