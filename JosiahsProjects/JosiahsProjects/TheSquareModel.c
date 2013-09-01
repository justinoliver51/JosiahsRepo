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
void freeSquareModel(void *);

// PRIVATE VARIABLES
// this is the array containing the locations for each of our blocks
static Location positionArray[NUMBER_OF_BLOCKS];
static ShapeModelPtr shapePtr;

SquareModelPtr initializeTheSquareModel()
{
    // INITIALIZE GLOBALS
    // Our initial score is 0
    
    // Initialize the struct that represents our ScoreBoard
    SquareModelPtr squarePtr = (SquareModelPtr) malloc(sizeof( TheSquareModel ) );  // Allocates memory for Thesquare
    
    shapePtr = initializeShapeModel();
    shapePtr->rotate = &rotate;
    squarePtr->free = &freeSquareModel;
    
    // Initialize
    positionArray[0].x = 3;
    positionArray[0].y = 0;
    positionArray[1].x = 3;
    positionArray[1].y = 1;
    positionArray[2].x = 3;
    positionArray[2].y = 2;
    positionArray[3].x = 3;
    positionArray[3].y = 3;
    
    return squarePtr;
}
// There are two positions for a square, vertical or horizontal.
void rotate()
{    
    return;
}


// Frees the allocated memory of the Score Model

void freeSquareModel(void *squareModel)
{
    
    SquareModelPtr squareModelPtr = (SquareModelPtr) squareModel;
    shapePtr->free(shapePtr);
    free(squareModelPtr);
}