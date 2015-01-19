//
//  arithmetic.h
//  TwoPlayerMathGame
//
//  Created by Renato Camilio on 1/18/15.
//  Copyright (c) 2015 Renato Camilio. All rights reserved.
//

#ifndef __TwoPlayerMathGame__arithmetic__
#define __TwoPlayerMathGame__arithmetic__

#include <stdio.h>

typedef struct arithmetic {
    float x;
    float y;
    float result;
    char *operationName;
} Arithmetic;

int generateRandomNumber(int max);
void generateRandomArithmetic(Arithmetic *arithmetic);

#endif /* defined(__TwoPlayerMathGame__arithmetic__) */
