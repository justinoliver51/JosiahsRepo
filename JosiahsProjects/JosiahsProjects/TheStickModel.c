//
//  TheStick.c
//  JosiahsProjects
//
//  Created by User on 8/30/13.
//  Copyright (c) 2013 Engineering. All rights reserved.
//

#include <stdio.h>
#include "TheStickModel.h"

#define NUMBER_OF_BLOCKS 4

void rotate();

// this is the array containing the locations for each of our blocks
static Location positionArray[NUMBER_OF_BLOCKS];

StickModelPtr initializeTheStickModel()
{
    // INITIALIZE GLOBALS
    // Our initial score is 0
    
    // Initialize the struct that represents our ScoreBoard
    StickModelPtr stickPtr = (StickModelPtr) malloc(sizeof( TheStickModel ) );  // Allocates memory for TheStick
    
    stickPtr->shapePtr = initializeShapeModel();
    stickPtr->shapePtr->rotate = &rotate;
    
    // Initialize
    positionArray[0].x = 0;
    positionArray[0].y = 0;
    positionArray[1].x = 0;
    positionArray[1].y = 0;
    positionArray[2].x = 0;
    positionArray[2].y = 0;
    positionArray[3].x = 0;
    positionArray[3].y = 0;
    
    return stickPtr;
}

// There are two positions for a stick, vertical or horizontal.
void rotate()
{
    return;
}