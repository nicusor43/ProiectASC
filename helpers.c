//
// Created by nicusor43 on 11/28/23.
//

#include "helpers.h"

uint64_t intToBin(long int intreg) {
    uint64_t binar = 0;

    while (intreg != 0){
        binar += intreg %2;
        binar *= 10;
        intreg /= 2;
    }

    return binar;
}
