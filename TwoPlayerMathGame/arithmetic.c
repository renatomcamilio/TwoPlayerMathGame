//
//  arithmetic.c
//  TwoPlayerMathGame
//
//  Created by Renato Camilio on 1/18/15.
//  Copyright (c) 2015 Renato Camilio. All rights reserved.
//

#include "arithmetic.h"
#include <stdlib.h>


int generateRandomNumber(int max) {
    int generated = arc4random_uniform(max) + 1;
    return generated;
}

void generateRandomArithmetic(Arithmetic *arithmetic) {
    char *operations[4] = { "plus", "minus", "times", "divided by" };
    int operation = generateRandomNumber(4) - 1;
    
    arithmetic->operationName = operations[operation];
    
    switch (operation) {
        case 0:
            arithmetic->result = arithmetic->x + arithmetic->y;
            break;
        case 1:
            arithmetic->result = arithmetic->x - arithmetic->y;
            break;
        case 2:
            arithmetic->result = arithmetic->x * arithmetic->y;
            break;
        case 3:
            arithmetic->result = arithmetic->x / arithmetic->y;
            break;
        default:
            break;
    }
}
