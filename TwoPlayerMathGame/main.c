//
//  main.c
//  TwoPlayerMathGame
//
//  Created by Renato Camilio on 1/18/15.
//  Copyright (c) 2015 Renato Camilio. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "arithmetic.h"
#include "player.h"



int main(int argc, const char * argv[]) {
    // Players init
    Player players[2];
    players[0].name = "Player 1";
    players[0].lives = 3;
    players[0].score = 0;
    players[1].name = "Player 2";
    players[1].lives = 3;
    players[1].score = 0;
    
    // Game manager
    float answer;
    int playerTurn = 2;
    Arithmetic arithmetic;
    Player *currentPlayer;
    
    while (players[0].lives && players[1].lives) {
        arithmetic.x = generateRandomNumber(20);
        arithmetic.y = generateRandomNumber(20);
        currentPlayer = &players[(playerTurn % 2)];
        
        generateRandomArithmetic(&arithmetic);
        
        printf("%s: What does %.0f %s %.0f equal?\n",
               currentPlayer->name,
               arithmetic.x,
               arithmetic.operationName,
               arithmetic.y);

        fscanf(stdin, "%f", &answer);
        
        if (answer == arithmetic.result) {
            printf("Nice, you're right!\n");
            ++currentPlayer->score;
        } else {
            printf("Oops! You're wrong. The right answer is %f\n", arithmetic.result);
            --currentPlayer->lives;
        }
        
        playerTurn++;
    }
    
    Player *winner = (players[0].lives) ? &players[0] : &players[1];
    printf("Game Over\n");
    printf("%s wins the Math Game! Score: %i - Lives: %i\n",
           winner->name,
           winner->score,
           winner->lives);

    return 0;
}
