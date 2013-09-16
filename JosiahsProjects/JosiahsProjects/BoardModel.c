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

ShapeModelPtr fallingShapePtr;

unsigned int fallSpeed;

unsigned int **board;

unsigned int xLen;

unsigned int yLen;

//declarations
int fall();
void destroyLine();
char lockShape();
void updateBoard();

// ******** intializeBoardModel **********
// This initializes our boardModel.
//
// Inputs:    None
//
// Outputs:   None

BoardModelPtr initializeBoardModel(unsigned int newXLen, unsigned int newYLen)
{
    // Local Variables
    int x, y;
    
    // INITIALIZE GLOBALS
    xLen = newXLen;
    yLen = newYLen;
    board = (unsigned int**) malloc(xLen * sizeof(int*));
    
    for (x = 0; x < xLen; x++) {
        // (0,0), (0,1), (0,2), ...
        board[x] = (unsigned int*) malloc(yLen * sizeof(int));
    }
    
    // Initialize all values to zero
    for(x = 0; x < xLen; x = x + 1)
        for(y = 0; y < yLen; y = y + 1)
            board[x][y] = 0;
    
    // Initialize the struct that represents our BoardBoard
    BoardModelPtr boardModelPtr = (BoardModelPtr) malloc(sizeof( BoardModel ) );  // Allocates memory for the boardboard
    
    boardModelPtr->updateBoard = &updateBoard;
    boardModelPtr->lockShape = &lockShape;
    boardModelPtr->destroyLine = &destroyLine;
    boardModelPtr->fall = &fall;
    
    
    return boardModelPtr;
}

// ******** fall **********
// makes shapes fall down the board 1 space
//
// Inputs:    None
//
// Outputs:   0 if shape is placed correctly, 1 if not
int fall()
{
    // Shifts the shape down one block on the board
    fallingShapePtr->move(0, -1);
    
    // If the shape can be placed, return 0
    if(1)
    {
        return 0;
    }
    // Otherwise return 1
    else
        return 1;
}

// ******** destroyLine **********
// Temoves a line of blocks if they are all filled
//
// Inputs:    None
//
// Outputs:   None
void destroyLine()
{
    
    
    return;
}

// ******** lockShape **********
// Locks the current shape in a position it cant move from and updates the board
//
// Inputs:    None
//
// Outputs:   1 if a line of blocks is filled, 0 if not
char lockShape()
{
    return 0;
}

// ******** updateBoard **********
// Called by an interrupt to update the state of the board
//
// Inputs:    None
//
// Outputs:   None

void updateBoard()
{
    int fallFinished = fall();
    int lineFilled;
    
    // this checks if the shape has reached the bottom of its decent
    if(fallFinished)
    {
        lineFilled = lockShape();
        
        // this checks if there is a full line of blocks needing to be removed
        if (lineFilled == 1)
        {
            destroyLine();
        }
    }

    
    return;
}


/*
 for (int i = 0; i < dimension1_max; i++) {
 free(x[i]);
 }
 free(x);
 */