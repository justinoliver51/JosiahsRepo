//
//  BoardModel.c
//  JosiahsProjects
//
//  Created by Justin Oliver on 9/10/13.
//  Copyright (c) 2013 Engineering. All rights reserved.
//

#include <stdio.h>
#include "BoardModel.h"


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

// All numbers besides 0 contain blocks
unsigned int **board;

unsigned int xLen;

unsigned int yLen;

// Function Declarations
int fall();
void destroyLine();
char lockShape();
void updateBoard();
void setFallingShape(ShapeModelPtr);
int findFilledLine();

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
    board = (unsigned int**) malloc(xLen * sizeof(int *));
    
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
    boardModelPtr->setFallingShape = &setFallingShape;
    
    
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
    int i = 0;
    Location positionArray[4];
    fallingShapePtr->getPositionArray(positionArray);
    
    // Shifts the shape down one block on the board
    fallingShapePtr->move(0, -1);
    fallingShapePtr->getPositionArray(positionArray);

    //i need a loop and i need to check every block in the shape for their location in the board to determine if its empty, if it is empty go to the next block, if not fall
    // if we reach the bottom
    // If the shape can be placed, return 0
    for(i = 0; i < 4; i++)
    {
        // Check if the y coordinate in the position array is legal  FIXME: Need to leave for Josiah.
        if(positionArray[i].y > (yLen + NUMBER_OF_BLOCKS))
        {
            fallingShapePtr->move(0, 1);
            return 1;
        }
        
        // positionarray[i] is a location
        //the locatio.x gives you the x coordinate, same for the location.y    FIXME: Need to leave for Josiah
        if( (positionArray[i].y < yLen) && (board[positionArray[i].x][positionArray[i].y] > 0) )
        {
            fallingShapePtr->move(0, 1);
            
            return 1;
        }
    }
    
    return 0;
}

// ******** setFallingShape **********
// Our setter for the falling shape
//
// Inputs:    A pointer to the falling shape
//
// Outputs:   None
void setFallingShape(ShapeModelPtr newFallingShapePtr)
{
    
    fallingShapePtr = newFallingShapePtr;
    
    return;
}

// ******** findFilledLine **********
// Checks coordinates to find "line"
//
// Inputs:    i,j
//
// Outputs:   line

int findFilledLine()
{
    int i,j;
    
    for(i = 0; i < yLen; i++)
    {
        for(j = 0; j < xLen; j++)
        {
            if(board[j][i] == 0)
            {
                break;
            }
        }
        
        if(j == xLen)
        {
            return j;
        }
    }

    return 0;
}
    
// ******** destroyLine **********
// Temoves a line of blocks if they are all filled
//
// Inputs:    None
//
// Outputs:   None
void destroyLine()
{
    
    //i need to reset the values of the line to 0 and then shift the blocks down
    int i,j,line= 0;
    
    line = findFilledLine();
    
    for(i = 0; i < xLen; i++)
    {
        // FIXME
        // this needs to destroy the correct line, not line zero
        board[i][line] = 0;
    }
    
    for(i = 0; i < xLen; i++)
    {
        for( j = line; j < yLen; j++)
        {
            //the variable line is my starting point, not 0
            board[i][j] = board[i][j + 1];
        }
    }
    
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
    int i;
    
    Location positionArray[4];
    
    fallingShapePtr->getPositionArray(positionArray);
    
    //the shape is supposed to be locked in position
    //i need another loop to go through each block and set the value of the board at the coordinates to 1
    
    for(i = 0; i < 4; i++)
    {
        // positionarray[i] is a location
        //the location.x gives you the x coordinate, same for the location.y
        
        board[positionArray[i].x][positionArray[i].y] = 1;  //FIXME: INSTEAD OF 1, NEEDS TO REFLECT THE                        COLOR WE WANT   
    }

    //IF A BLOCKS COORDINATES IS 1, IT IS FILLED
    return findFilledLine();
    
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
    
    
