//
// Created by nicusor43 on 11/23/23.
//

#include "assembler.h"
#include <stdio.h>

// Enum of RISC-V instructions
enum RiscInstructions {
    ADD = 1,
    SUB = 2,
    XOR = 3,
    OR = 4,
    AND = 5,
    SLL = 6,
    SRL = 7,
    SRA = 8,
    SLT = 9,
    SLTU = 10,
    ADDI = 11,
    XORI = 12,
    ORI = 13,
    ANDI = 14,
    SLLI = 15,
    SRLI = 16,
    SRAI = 17,
    SLTI = 18,
    SLTIU = 19,
    LB = 20,
    LH = 21,
    LW = 22,
    LBU = 23,
    LHU = 24,
    SB = 25,
    SH = 26,
    SW = 27,
    BEQ = 28,
    BNE = 29,
    BLT = 30,
    BGE = 31,
    BLTU = 32,
    BGEU = 33,
    JAL = 34,
    JALR = 35,
    LUI = 36,
    AUIPC = 37,
    ECALL = 38,
    EBREAK = 39,
    BEQZ = 40,
    BNEZ = 41,
    FLD = 42,
    FSW = 43,
    BGT = 44,
    CALL = 45,
    FMVSX = 46,
    FMULS = 47,
    FADDS = 48,
    SD = 49,
};

int main(int argc, char * argv[]){

}