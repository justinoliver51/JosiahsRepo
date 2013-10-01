//
//  TheSquareModel.c
//  JosiahsProjects
//
//  Created by User on 8/30/13.
//  Copyright (c) 2013 Engineering. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "TheSquareModel.h"

#define NUMBER_OF_BLOCKS 4

// FUNCTION DECLARATIONS
void rotate();
void rotateSquare();
void freeSquareModel(void *);
void moveSquare(int x, int y);
void getSquarePositionArray(LocationPtr);

// PRIVATE VARIABLES
// this is the array containing the locations for each of our blocks
static Location positionArray[NUMBER_OF_BLOCKS];
static SquareModelPtr squarePtr;

SquareModelPtr initializeTheSquareModel()
{
    // INITIALIZE GLOBALS
    // Our initial score is 0
    
    // Initialize the struct that represents our ScoreBoard
    squarePtr = (SquareModelPtr) malloc(sizeof( TheSquareModel ) );  // Allocates memory for Thesquare
    
    squarePtr->shapePtr = initializeShapeModel();
    squarePtr->shapePtr->rotate = &rotateSquare;
    squarePtr->shapePtr->move = &moveSquare;
    squarePtr->free = &freeSquareModel;
    squarePtr->shapePtr->getPositionArray = &getSquarePositionArray;
    
    
    // Initialize
    positionArray[0].x = 0;
    positionArray[0].y = 0;
    positionArray[1].x = 0;
    positionArray[1].y = 1;
    positionArray[2].x = 1;
    positionArray[2].y = 0;
    positionArray[3].x = 1;
    positionArray[3].y = 1;
    
    return squarePtr;
}

void moveSquare(int x, int y)
{
    positionArray[0].x = positionArray[0].x + x;
    positionArray[0].y = positionArray[0].y + y;
    positionArray[1].x = positionArray[1].x + x;
    positionArray[1].y = positionArray[1].y + y;
    positionArray[2].x = positionArray[2].x + x;
    positionArray[2].y = positionArray[2].y + y;
    positionArray[3].x = positionArray[3].x + x;
    positionArray[3].y = positionArray[3].y + y;
    
    
    return;
}

// There are two positions for a square, vertical or horizontal.
// There are two positions for a square, vertical or horizontal.
void rotateSquare()
{
    squarePtr->shapePtr->setState(0);
    
    return;
}


// Frees the allocated memory of the Score Model


// Frees the allocated memory of the Score Model

void freeSquareModel(void *squareModel)
{
    SquareModelPtr squareModelPtr = (SquareModelPtr) squareModel;
    squareModelPtr->shapePtr->free(squareModelPtr->shapePtr);
    free(squareModelPtr);
}

// Returns a copy of the positionArray
void getSquarePositionArray(LocationPtr positionArrayCopy)
{
    positionArrayCopy[0].x = positionArray[0].x;
    positionArrayCopy[0].y = positionArray[0].y;
    positionArrayCopy[1].x = positionArray[1].x;
    positionArrayCopy[1].y = positionArray[1].y;
    positionArrayCopy[2].x = positionArray[2].x;
    positionArrayCopy[2].y = positionArray[2].y;
    positionArrayCopy[3].x = positionArray[3].x;
    positionArrayCopy[3].y = positionArray[3].y;
    
    return;
}

