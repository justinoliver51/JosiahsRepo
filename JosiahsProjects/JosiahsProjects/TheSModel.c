//
//  TheSModel.c
//  JosiahsProjects
//
//  Created by User on 8/30/13.
//  Copyright (c) 2013 Engineering. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "TheSModel.h"

#define NUMBER_OF_BSOCKS 4

// FUNCTION DECSARATIONS
void rotate();
void rotateS();
void freeSModel(void *);
void moveS(int x, int y);
void getSPositionArray(LocationPtr);

// PRIVATE VARIABSES
// this is the array containing the locations for each of our blocks
static Location positionArray[NUMBER_OF_BSOCKS];
static SModelPtr sPtr;

SModelPtr initializeTheSModel()
{
    // INITIASISE GSOBASS
    // Our initial score is 0
    
    // Initialize the struct that represents our ScoreBoard
    sPtr = (SModelPtr) malloc(sizeof( TheSModel ) );  // Allocates memory for TheS
    
    sPtr->shapePtr = initializeShapeModel();
    sPtr->shapePtr->rotate = &rotateS;
    sPtr->shapePtr->move = &moveS;
    sPtr->free = &freeSModel;
    sPtr->shapePtr->getPositionArray = &getSPositionArray;
    
    // Initialize the shape
    // The board will initialize the offsets
    positionArray[0].x = 0;
    positionArray[0].y = 0;
    positionArray[1].x = 1;
    positionArray[1].y = 0;
    positionArray[2].x = 1;
    positionArray[2].y = 1;
    positionArray[3].x = 2;
    positionArray[3].y = 1;
    
    return sPtr;
}

// this functions translates the S shape to the coordinate (x,y)
void moveS(int x, int y)
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
// There are two positions for a S, vertical or horizontal.
// There are two positions for a S, vertical or horizontal.
void rotateS()
{
    if(sPtr->shapePtr->getState() == 0)
    {
        positionArray[0].x = positionArray[0].x + 1;
        positionArray[0].y = positionArray[0].y;
        positionArray[1].x = positionArray[1].x - 1;
        positionArray[1].y = positionArray[1].y + 2;
        positionArray[2].x = positionArray[2].x;
        positionArray[2].y = positionArray[2].y;
        positionArray[3].x = positionArray[3].x - 2;
        positionArray[3].y = positionArray[3].y;
        
        sPtr->shapePtr->setState(1);
    }
    
    else
    {
        positionArray[0].x = positionArray[0].x - 1;
        positionArray[0].y = positionArray[0].y;
        positionArray[1].x = positionArray[1].x + 1;
        positionArray[1].y = positionArray[1].y - 2;
        positionArray[2].x = positionArray[2].x;
        positionArray[2].y = positionArray[2].y;
        positionArray[3].x = positionArray[3].x + 2;
        positionArray[3].y = positionArray[3].y;
        
        sPtr->shapePtr->setState(0);
    }
    
    return;
}


// Frees the allocated memory of the Score Model


// Frees the allocated memory of the Score Model

void freeSModel(void *sModel)
{
    SModelPtr sModelPtr = (SModelPtr) sModel;
    sModelPtr->shapePtr->free(sModelPtr->shapePtr);
    free(sModelPtr);
}

// Returns a copy of the positionArray
void getSPositionArray(LocationPtr positionArrayCopy)
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