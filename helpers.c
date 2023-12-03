//
// Created by nicusor43 on 11/28/23.
//

#include "helpers.h"

// O idee foarte proasta, un int64 poate avea maxim 19 cifre, deci nu se putem converti un binar de 32 de biti..
// A NU SE FOLOSI
/*
uint64_t intToBin(long int intreg) {
    uint64_t binar = 0;

    while (intreg != 0) {
        binar += intreg % 2;
        binar *= 10;
        intreg /= 2;
    }

    return binar;
}
 */

char *strrev(char *str){
    if (!str || ! *str)
        return str;

    int i = strlen(str) - 1, j = 0;

    char ch;
    while (i > j)
    {
        ch = str[i];
        str[i] = str[j];
        str[j] = ch;
        i--;
        j++;
    }
    return str;
}
