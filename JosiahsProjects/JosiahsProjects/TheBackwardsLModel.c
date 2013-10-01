//
//  TheBackwardsLModel.c
//  JosiahsProjects
//
//  Created by User on 8/30/13.
//  Copyright (c) 2013 Engineering. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "TheBackwardsLModel.h"

#define NUMBER_OF_BBackwardsLOCKS 4

// FUNCTION DECBackwardsLARATIONS
void rotate();
void rotateBackwardsL();
void freeBackwardsLModel(void *);
void moveBackwardsL(int x, int y);
void getBackwardsLPositionArray(LocationPtr);

// PRIVATE VARIABBackwardsLES
// this is the array containing the locations for each of our blocks
static Location positionArray[NUMBER_OF_BBackwardsLOCKS];
static BackwardsLModelPtr backwardsLPtr;

BackwardsLModelPtr initializeTheBackwardsLModel()
{
    // INITIABackwardsLIZE GBackwardsLOBABackwardsLS
    // Our initial score is 0
    
    // Initialize the struct that represents our ScoreBoard
    backwardsLPtr = (BackwardsLModelPtr) malloc(sizeof( TheBackwardsLModel ) );  // Allocates memory for TheBackwardsL
    
    backwardsLPtr->shapePtr = initializeShapeModel();
    backwardsLPtr->shapePtr->rotate = &rotateBackwardsL;
    backwardsLPtr->shapePtr->move = &moveBackwardsL;
    backwardsLPtr->free = &freeBackwardsLModel;
    backwardsLPtr->shapePtr->getPositionArray = &getBackwardsLPositionArray;
    
    // Initialize the shape
    // The board will initialize the offsets
    positionArray[0].x = 1;
    positionArray[0].y = 0;
    positionArray[1].x = 2;
    positionArray[1].y = 0;
    positionArray[2].x = 2;
    positionArray[2].y = 1;
    positionArray[3].x = 2;
    positionArray[3].y = 2;
    
    return backwardsLPtr;
}

// this functions translates the BackwardsL shape to the coordinate (x,y)
void moveBackwardsL(int x, int y)
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
// There are two positions for a BackwardsL, vertical or horizontal.
// There are two positions for a BackwardsL, vertical or horizontal.
void rotateBackwardsL()
{
    if(backwardsLPtr->shapePtr->getState() == 0)
    {
        positionArray[0].x = positionArray[0].x;
        positionArray[0].y = positionArray[0].y;
        positionArray[1].x = positionArray[1].x;
        positionArray[1].y = positionArray[1].y;
        positionArray[2].x = positionArray[2].x - 2;
        positionArray[2].y = positionArray[2].y;
        positionArray[3].x = positionArray[3].x - 2;
        positionArray[3].y = positionArray[3].y - 2;
        
        backwardsLPtr->shapePtr->setState(1);
    }
    
    else if(backwardsLPtr->shapePtr->getState() == 1)
    {
        positionArray[0].x = positionArray[0].x - 1;
        positionArray[0].y = positionArray[0].y + 2;
        positionArray[1].x = positionArray[1].x - 1;
        positionArray[1].y = positionArray[1].y + 2;
        positionArray[2].x = positionArray[2].x;
        positionArray[2].y = positionArray[2].y;
        positionArray[3].x = positionArray[3].x;
        positionArray[3].y = positionArray[3].y;
        
        backwardsLPtr->shapePtr->setState(2);
    }
    
    else if(backwardsLPtr->shapePtr->getState() == 2)
    {
        positionArray[0].x = positionArray[0].x + 1;
        positionArray[0].y = positionArray[0].y - 1;
        positionArray[1].x = positionArray[1].x + 1;
        positionArray[1].y = positionArray[1].y - 1;
        positionArray[2].x = positionArray[2].x;
        positionArray[2].y = positionArray[2].y;
        positionArray[3].x = positionArray[3].x;
        positionArray[3].y = positionArray[3].y;
        
        backwardsLPtr->shapePtr->setState(3);
    }
    
    else
    {
        positionArray[0].x = positionArray[0].x;
        positionArray[0].y = positionArray[0].y - 1;
        positionArray[1].x = positionArray[1].x;
        positionArray[1].y = positionArray[1].y - 1;
        positionArray[2].x = positionArray[2].x + 2;
        positionArray[2].y = positionArray[2].y;
        positionArray[3].x = positionArray[3].x + 2;
        positionArray[3].y = positionArray[3].y + 2;
        
        backwardsLPtr->shapePtr->setState(0);
    }
    
    return;
}


// Frees the allocated memory of the Score Model


// Frees the allocated memory of the Score Model

void freeBackwardsLModel(void *backwardsLModel)
{
    BackwardsLModelPtr backwardsLModelPtr = (BackwardsLModelPtr) backwardsLModel;
    backwardsLModelPtr->shapePtr->free(backwardsLModelPtr->shapePtr);
    free(backwardsLModelPtr);
}

// Returns a copy of the positionArray
void getBackwardsLPositionArray(LocationPtr positionArrayCopy)
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