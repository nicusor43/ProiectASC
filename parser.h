//
// Created by nicusor43 on 11/24/23.
//

#ifndef PROIECTASC_PARSER_H
#define PROIECTASC_PARSER_H

#include "stdlib.h"
#include "stdio.h"
#include "string.h"

void printHelp();

void parseFile(char *input_file, char *output_file);

char *checkInstruction(char *instruction);

#endif //PROIECTASC_PARSER_H
