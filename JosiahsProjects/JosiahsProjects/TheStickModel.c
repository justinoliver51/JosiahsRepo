//
//  TheStick.c
//  JosiahsProjects
//
//  Created by User on 8/30/13.
//  Copyright (c) 2013 Engineering. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "TheStickModel.h"

#define NUMBER_OF_BLOCKS 4

// FUNCTION DECLARATIONS
void rotate();
void rotateStick();
void freeStickModel(void *);

// PRIVATE VARIABLES
// this is the array containing the locations for each of our blocks
static Location positionArray[NUMBER_OF_BLOCKS];
static ShapeModelPtr shapePtr;

StickModelPtr initializeTheStickModel()
{
    // INITIALIZE GLOBALS
    // Our initial score is 0
    
    // Initialize the struct that represents our ScoreBoard
    StickModelPtr stickPtr = (StickModelPtr) malloc(sizeof( TheStickModel ) );  // Allocates memory for TheStick
    
    shapePtr = initializeShapeModel();
    shapePtr->rotate = &rotateStick;
    stickPtr->free = &freeStickModel;
    
    // Initialize
    positionArray[0].x = 3;
    positionArray[0].y = 0;
    positionArray[1].x = 3;
    positionArray[1].y = 1;
    positionArray[2].x = 3;
    positionArray[2].y = 2;
    positionArray[3].x = 3;
    positionArray[3].y = 3;
    
    return stickPtr;
}

// There are two positions for a stick, vertical or horizontal.
void rotateStick()
{
    if(shapePtr->getState() == 0)
    {
        
        positionArray[0].x = positionArray[0].x - 3;
        positionArray[0].y = positionArray[0].y - 0;
        positionArray[1].x = positionArray[1].x - 3;
        positionArray[1].y = positionArray[1].y - 1;
        positionArray[2].x = positionArray[2].x - 3;
        positionArray[2].y = positionArray[2].y - 2;
        positionArray[3].x = positionArray[3].x - 3;
        positionArray[3].y = positionArray[3].y - 3;
        
        shapePtr->setState(1);
    }
    
    if(shapePtr->getState() == 1)
    {
        
        
        positionArray[0].x = positionArray[0].x + 3;
        positionArray[0].y = positionArray[0].y + 0;
        positionArray[1].x = positionArray[1].x + 3;
        positionArray[1].y = positionArray[1].y + 1;
        positionArray[2].x = positionArray[2].x + 3;
        positionArray[2].y = positionArray[2].y + 2;
        positionArray[3].x = positionArray[3].x + 3;
        positionArray[3].y = positionArray[3].y + 3;
        
        shapePtr->setState(0);
    }
    
    
    
    return;
}


// Frees the allocated memory of the Score Model
void freeStickModel(void *stickModel)
{
    
    StickModelPtr stickModelPtr = (StickModelPtr) stickModel;
    shapePtr->free(shapePtr);
    free(stickModelPtr);
}