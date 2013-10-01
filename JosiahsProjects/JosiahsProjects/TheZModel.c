//
//  TheZModel.c
//  JosiahsProjects
//
//  Created by User on 8/30/13.
//  Copyright (c) 2013 Engineering. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "TheZModel.h"

#define NUMBER_OF_BZOCKS 4

// FUNCTION DECZARATIONS
void rotate();
void rotateZ();
void freeZModel(void *);
void moveZ(int x, int y);
void getZPositionArray(LocationPtr);

// PRIVATE VARIABZES
// this is the array containing the locations for each of our blocks
static Location positionArray[NUMBER_OF_BZOCKS];
static ZModelPtr zPtr;

ZModelPtr initializeTheZModel()
{
    // INITIAZIZE GZOBAZS
    // Our initial score is 0
    
    // Initialize the struct that represents our ScoreBoard
    zPtr = (ZModelPtr) malloc(sizeof( TheZModel ) );  // Allocates memory for TheZ
    
    zPtr->shapePtr = initializeShapeModel();
    zPtr->shapePtr->rotate = &rotateZ;
    zPtr->shapePtr->move = &moveZ;
    zPtr->free = &freeZModel;
    zPtr->shapePtr->getPositionArray = &getZPositionArray;
    
    // Initialize the shape
    // The board will initialize the offsets
    positionArray[0].x = 2;
    positionArray[0].y = 0;
    positionArray[1].x = 1;
    positionArray[1].y = 0;
    positionArray[2].x = 1;
    positionArray[2].y = 1;
    positionArray[3].x = 0;
    positionArray[3].y = 1;
    
    return zPtr;
}

// this functions translates the Z shape to the coordinate (x,y)
void moveZ(int x, int y)
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
// There are two positions for a Z, vertical or horizontal.
// There are two positions for a Z, vertical or horizontal.
void rotateZ()
{
    if(zPtr->shapePtr->getState() == 0)
    {
        positionArray[0].x = positionArray[0].x - 1;
        positionArray[0].y = positionArray[0].y + 1;
        positionArray[1].x = positionArray[1].x;
        positionArray[1].y = positionArray[1].y;
        positionArray[2].x = positionArray[2].x + 1;
        positionArray[2].y = positionArray[2].y;
        positionArray[3].x = positionArray[3].x + 2;
        positionArray[3].y = positionArray[3].y + 1;
        
        zPtr->shapePtr->setState(1);
    }
    
     else
    {
        positionArray[0].x = positionArray[0].x + 1;
        positionArray[0].y = positionArray[0].y - 1;
        positionArray[1].x = positionArray[1].x;
        positionArray[1].y = positionArray[1].y;
        positionArray[2].x = positionArray[2].x - 1;
        positionArray[2].y = positionArray[2].y;
        positionArray[3].x = positionArray[3].x - 2;
        positionArray[3].y = positionArray[3].y - 1;
        
        zPtr->shapePtr->setState(0);
    }
    
    return;
}


// Frees the allocated memory of the Score Model


// Frees the allocated memory of the Score Model

void freeZModel(void *zModel)
{
    ZModelPtr zModelPtr = (ZModelPtr) zModel;
    zModelPtr->shapePtr->free(zModelPtr->shapePtr);
    free(zModelPtr);
}

// Returns a copy of the positionArray
void getZPositionArray(LocationPtr positionArrayCopy)
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