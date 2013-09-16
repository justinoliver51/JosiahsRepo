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

unsigned int *board;

unsigned int xLen;

unsigned int yLen;

//declarations
int fall();
void destroyLine();
void lockShape();
void updateBoard();

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
// makes shapes fall down the board 1 space
//
// Inputs:    None
//
// Outputs:   0 if shape is placed correctly, 1 if not
void destroyLine()
{
    return;
}

// ******** lockShape **********
// makes shapes fall down the board 1 space
//
// Inputs:    None
//
// Outputs:   0 if shape is placed correctly, 1 if not
void lockShape()
{
    return;
}

void updateBoard()
{
    //this function is supposed to decide when each other function is called
    int 
    int fellIncorrectly = fall();
    
    // If 
    if(fellIncorrectly)
    {
        lockShape();
        
        if(lockShape() == 0)
        {
            void destroyLine();
        }
    }

    
    return;
}








