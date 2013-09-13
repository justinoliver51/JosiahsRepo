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
    shapePtr->rotate = &rotateSquare;
    shapePtr->move = &moveSquare;
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

    
 shapePtr->setState(0);    
    
    return;
}


// Frees the allocated memory of the Score Model


// Frees the allocated memory of the Score Model

void freeSquareModel(void *squareModel)
{
    
    SquareModelPtr squareModelPtr = (SquareModelPtr) squareModel;
    shapePtr->free(shapePtr);
    free(squareModelPtr);
}