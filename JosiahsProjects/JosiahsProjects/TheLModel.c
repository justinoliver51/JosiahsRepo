//
//  TheLModel.c
//  JosiahsProjects
//
//  Created by User on 8/30/13.
//  Copyright (c) 2013 Engineering. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "TheLModel.h"

#define NUMBER_OF_BLOCKS 4

// FUNCTION DECLARATIONS
void rotate();
void rotateL();
void freeLModel(void *);
void moveL(int x, int y);
void getLPositionArray(LocationPtr);

// PRIVATE VARIABLES
// this is the array containing the locations for each of our blocks
static Location positionArray[NUMBER_OF_BLOCKS];
static LModelPtr lPtr;

LModelPtr initializeTheLModel()
{
    // INITIALIZE GLOBALS
    // Our initial score is 0
    
    // Initialize the struct that represents our ScoreBoard
    lPtr = (LModelPtr) malloc(sizeof( TheLModel ) );  // Allocates memory for TheL
    
    lPtr->shapePtr = initializeShapeModel();
    lPtr->shapePtr->rotate = &rotateL;
    lPtr->shapePtr->move = &moveL;
    lPtr->free = &freeLModel;
    lPtr->shapePtr->getPositionArray = &getLPositionArray;
    
    // Initialize the shape
    // The board will initialize the offsets
    positionArray[0].x = 0;
    positionArray[0].y = 0;
    positionArray[1].x = 1;
    positionArray[1].y = 0;
    positionArray[2].x = 0;
    positionArray[2].y = 1;
    positionArray[3].x = 0;
    positionArray[3].y = 2;
    
    return lPtr;
}

// this functions translates the L shape to the coordinate (x,y)
void moveL(int x, int y)
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
// There are two positions for a L, vertical or horizontal.
// There are two positions for a L, vertical or horizontal.
void rotateL()
{
    if(lPtr->shapePtr->getState() == 0)
    {
        positionArray[0].x = positionArray[0].x;
        positionArray[0].y = positionArray[0].y;
        positionArray[1].x = positionArray[1].x + 1;
        positionArray[1].y = positionArray[1].y + 1;
        positionArray[2].x = positionArray[2].x;
        positionArray[2].y = positionArray[2].y;
        positionArray[3].x = positionArray[3].x + 1;
        positionArray[3].y = positionArray[3].y - 1;
        
        lPtr->shapePtr->setState(1);
    }
    
    else if(lPtr->shapePtr->getState() == 1)
    {
        positionArray[0].x = positionArray[0].x + 1;
        positionArray[0].y = positionArray[0].y;
        positionArray[1].x = positionArray[1].x - 2;
        positionArray[1].y = positionArray[1].y + 1;
        positionArray[2].x = positionArray[2].x + 1;
        positionArray[2].y = positionArray[2].y + 1;
        positionArray[3].x = positionArray[3].x;
        positionArray[3].y = positionArray[3].y;
        
        lPtr->shapePtr->setState(2);
    }
    
    else if(lPtr->shapePtr->getState() == 2)
    {
        positionArray[0].x = positionArray[0].x;
        positionArray[0].y = positionArray[0].y;
        positionArray[1].x = positionArray[1].x + 2;
        positionArray[1].y = positionArray[1].y - 1;
        positionArray[2].x = positionArray[2].x - 1;
        positionArray[2].y = positionArray[2].y - 2;
        positionArray[3].x = positionArray[3].x + 1;
        positionArray[3].y = positionArray[3].y - 1;
        
        lPtr->shapePtr->setState(3);
    }
    
    else 
    {
        positionArray[0].x = positionArray[0].x - 1;
        positionArray[0].y = positionArray[0].y;
        positionArray[1].x = positionArray[1].x - 1;
        positionArray[1].y = positionArray[1].y - 1;
        positionArray[2].x = positionArray[2].x;
        positionArray[2].y = positionArray[2].y + 1;
        positionArray[3].x = positionArray[3].x - 2;
        positionArray[3].y = positionArray[3].y + 2;
        
        lPtr->shapePtr->setState(0);
    }
    
    return;
}


// Frees the allocated memory of the Score Model


// Frees the allocated memory of the Score Model

void freeLModel(void *lModel)
{
    LModelPtr lModelPtr = (LModelPtr) lModel;
    lModelPtr->shapePtr->free(lModelPtr->shapePtr);
    free(lModelPtr);
}

// Returns a copy of the positionArray
void getLPositionArray(LocationPtr positionArrayCopy)
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