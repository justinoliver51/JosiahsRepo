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

// PRIVATE VARIABLES
// this is the array containing the locations for each of our blocks
static Location positionArray[NUMBER_OF_BLOCKS];
static ShapeModelPtr shapePtr;

LModelPtr initializeTheLModel()
{
    // INITIALIZE GLOBALS
    // Our initial score is 0
    
    // Initialize the struct that represents our ScoreBoard
    LModelPtr lPtr = (LModelPtr) malloc(sizeof( TheLModel ) );  // Allocates memory for TheL
    
    shapePtr = initializeShapeModel();
    shapePtr->rotate = &rotateL;
    lPtr->free = &freeLModel;
    
    // Initialize
    positionArray[0].x = 3;
    positionArray[0].y = 0;
    positionArray[1].x = 3;
    positionArray[1].y = 1;
    positionArray[2].x = 3;
    positionArray[2].y = 2;
    positionArray[3].x = 3;
    positionArray[3].y = 3;
    
    return lPtr;
}
// There are two positions for a L, vertical or horizontal.
// There are two positions for a L, vertical or horizontal.
void rotateL()
{
    if(shapePtr->getState() == 0)
    {
        
        positionArray[0].x = positionArray[0].x;
        positionArray[0].y = positionArray[0].y;
        positionArray[1].x = positionArray[1].x - 1;
        positionArray[1].y = positionArray[1].y;
        positionArray[2].x = positionArray[2].x - 1;
        positionArray[2].y = positionArray[2].y - 1;
        positionArray[3].x = positionArray[3].x - 1;
        positionArray[3].y = positionArray[3].y - 2;
        
        
    }
    shapePtr->setState(1);
    
    if(shapePtr->getState() == 1)
    {
        
        positionArray[0].x = positionArray[0].x;
        positionArray[0].y = positionArray[0].y;
        positionArray[1].x = positionArray[1].x;
        positionArray[1].y = positionArray[1].y - 1;
        positionArray[2].x = positionArray[2].x - 1;
        positionArray[2].y = positionArray[2].y;
        positionArray[3].x = positionArray[3].x - 2;
        positionArray[3].y = positionArray[3].y;

    }
    shapePtr->setState(2);
    
    if(shapePtr->getState() == 2)
    {
        
        positionArray[0].x = positionArray[0].x;
        positionArray[0].y = positionArray[0].y;
        positionArray[1].x = positionArray[1].x;
        positionArray[1].y = positionArray[1].y - 1;
        positionArray[2].x = positionArray[2].x;
        positionArray[2].y = positionArray[2].y - 2;
        positionArray[3].x = positionArray[3].x - 1;
        positionArray[3].y = positionArray[3].y - 2;
        
    }
    shapePtr->setState(3);
    
    if(shapePtr->getState() == 3)
    {
        
        positionArray[0].x = positionArray[0].x;
        positionArray[0].y = positionArray[0].y;
        positionArray[1].x = positionArray[1].x;
        positionArray[1].y = positionArray[1].y + 1;
        positionArray[2].x = positionArray[2].x;
        positionArray[2].y = positionArray[2].y + 2;
        positionArray[3].x = positionArray[3].x + 1;
        positionArray[3].y = positionArray[3].y + 2;
 
    }
    shapePtr->setState(2);
    
    if(shapePtr->getState() == 2)
    {
        
        positionArray[0].x = positionArray[0].x;
        positionArray[0].y = positionArray[0].y;
        positionArray[1].x = positionArray[1].x;
        positionArray[1].y = positionArray[1].y + 1;
        positionArray[2].x = positionArray[2].x + 1;
        positionArray[2].y = positionArray[2].y;
        positionArray[3].x = positionArray[3].x + 2;
        positionArray[3].y = positionArray[3].y;

    }
    shapePtr->setState(1);
    
    if(shapePtr->getState() == 1)
    {
        
        positionArray[0].x = positionArray[0].x;
        positionArray[0].y = positionArray[0].y;
        positionArray[1].x = positionArray[1].x + 1;
        positionArray[1].y = positionArray[1].y;
        positionArray[2].x = positionArray[2].x + 1;
        positionArray[2].y = positionArray[2].y + 1;
        positionArray[3].x = positionArray[3].x + 1;
        positionArray[3].y = positionArray[3].y + 2;
        
    }


    shapePtr->setState(0);
    
    return;
}


// Frees the allocated memory of the Score Model


// Frees the allocated memory of the Score Model

void freeLModel(void *lModel)
{
    
    LModelPtr lModelPtr = (LModelPtr) lModel;
    shapePtr->free(shapePtr);
    free(lModelPtr);
}