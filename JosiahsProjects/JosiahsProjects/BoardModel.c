//
//  BoardModel.c
//  JosiahsProjects
//
//  Created by Justin Oliver on 9/10/13.
//  Copyright (c) 2013 Engineering. All rights reserved.
//

#include <stdio.h>
#include "BoardModel.h"
#include "ShapeModel.h"


/*
⁃	falling shape
⁃	fall speed
⁃	2-dimensional array of chars representing the board
⁃	xlen - number of blocks long in x
⁃	ylen - number of blocks long in y
*/

  // Example of a one-dimensional array
 // example of a two dimensional array representing x coordinate and y coordinate

ShapeModelPtr fallingShape;

unsigned int fallSpeed;

unsigned int *board;

unsigned int xLen;

unsigned int yLen;



// ******** intializeBoardModel **********
// This initializes our boardModel.
//
// Inputs:    None
//
// Outputs:   None

BoardModelPtr initializeBoardModel()
{
    // INITIALIZE GLOBALS
    // Our initial board is 0
    board = 0;
    
    // Initialize the struct that represents our BoardBoard
    BoardModelPtr boardModelPtr = (BoardModelPtr) malloc(sizeof( BoardModel ) );  // Allocates memory for the boardboard
    
    /*
    boardModelPtr->updateBoard = &updateBoard;
    boardModelPtr->getBoard = &getBoard;
    boardModelPtr->free = &freeBoardModel;
    */
    
    return boardModelPtr;
}

void fall()
{
    

    return;
}