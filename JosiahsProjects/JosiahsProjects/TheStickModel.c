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
void moveStick(int x, int y);
void getStickPositionArray(LocationPtr);

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
    shapePtr->move = &moveStick;
    stickPtr->free = &freeStickModel;
    shapePtr->getPositionArray = &getStickPositionArray;
    
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
// this functions translates the L shape to the coordinate (x,y)
void moveStick(int x, int y)
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

// Returns a copy of the positionArray
void getStickPositionArray(LocationPtr positionArrayCopy)
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