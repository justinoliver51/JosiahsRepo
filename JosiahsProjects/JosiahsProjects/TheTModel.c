//
//  TModel.c
//  JosiahsProjects
//
//  Created by User on 8/30/13.
//  Copyright (c) 2013 Engineering. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "TheTModel.h"

#define NUMBER_OF_BTOCKS 4

// FUNCTION DECTARATIONS
void rotate();
void rotateT();
void freeTModel(void *);
void moveT(int x, int y);
void getTPositionArray(LocationPtr);

// PRIVATE VARIABTES
// this is the array containing the locations for each of our blocks
static Location positionArray[NUMBER_OF_BTOCKS];
static TModelPtr tPtr;

TModelPtr initializeTModel()
{
    // INITIATIZE GTOBATS
    // Our initial score is 0
    
    // Initialize the struct that represents our ScoreBoard
    tPtr = (TModelPtr) malloc(sizeof( TModel ) );  // Allocates memory for T
    
    tPtr->shapePtr = initializeShapeModel();
    tPtr->shapePtr->rotate = &rotateT;
    tPtr->shapePtr->move = &moveT;
    tPtr->free = &freeTModel;
    tPtr->shapePtr->getPositionArray = &getTPositionArray;
    
    // Initialize the shape
    // The board will initialize the offsets
    positionArray[0].x = 1;
    positionArray[0].y = 1;
    positionArray[1].x = 2;
    positionArray[1].y = 1;
    positionArray[2].x = 0;
    positionArray[2].y = 1;
    positionArray[3].x = 1;
    positionArray[3].y = 2;
    
    return tPtr;
}

// this functions translates the T shape to the coordinate (x,y)
void moveT(int x, int y)
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
// There are two positions for a T, vertical or horizontal.
// There are two positions for a T, vertical or horizontal.
void rotateT()
{
    if(tPtr->shapePtr->getState() == 0)
    {
        positionArray[0].x = positionArray[0].x;
        positionArray[0].y = positionArray[0].y;
        positionArray[1].x = positionArray[1].x;
        positionArray[1].y = positionArray[1].y;
        positionArray[2].x = positionArray[2].x + 1;
        positionArray[2].y = positionArray[2].y - 1;
        positionArray[3].x = positionArray[3].x;
        positionArray[3].y = positionArray[3].y;
        
        tPtr->shapePtr->setState(1);
    }
    
    else if(tPtr->shapePtr->getState() == 1)
    {
        positionArray[0].x = positionArray[0].x;
        positionArray[0].y = positionArray[0].y;
        positionArray[1].x = positionArray[1].x;
        positionArray[1].y = positionArray[1].y;
        positionArray[2].x = positionArray[2].x;
        positionArray[2].y = positionArray[2].y;
        positionArray[3].x = positionArray[3].x - 1;
        positionArray[3].y = positionArray[3].y - 1;
        
        tPtr->shapePtr->setState(2);
    }
    
    else if(tPtr->shapePtr->getState() == 2)
    {
        positionArray[0].x = positionArray[0].x;
        positionArray[0].y = positionArray[0].y;
        positionArray[1].x = positionArray[1].x - 1;
        positionArray[1].y = positionArray[1].y + 1;
        positionArray[2].x = positionArray[2].x;
        positionArray[2].y = positionArray[2].y;
        positionArray[3].x = positionArray[3].x;
        positionArray[3].y = positionArray[3].y;
        
        tPtr->shapePtr->setState(3);
    }
    
    else
    {
        positionArray[0].x = positionArray[0].x;
        positionArray[0].y = positionArray[0].y;
        positionArray[1].x = positionArray[1].x + 1;
        positionArray[1].y = positionArray[1].y - 1;
        positionArray[2].x = positionArray[2].x + 1;
        positionArray[2].y = positionArray[2].y + 1;
        positionArray[3].x = positionArray[3].x - 1;
        positionArray[3].y = positionArray[3].y + 1;
        
        tPtr->shapePtr->setState(0);
    }
    
    return;
}


// Frees the allocated memory of the Score Model


// Frees the allocated memory of the Score Model

void freeTModel(void *tModel)
{
    TModelPtr tModelPtr = (TModelPtr) tModel;
    tModelPtr->shapePtr->free(tModelPtr->shapePtr);
    free(tModelPtr);
}

// Returns a copy of the positionArray
void getTPositionArray(LocationPtr positionArrayCopy)
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