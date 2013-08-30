//
//  TheStick.c
//  JosiahsProjects
//
//  Created by User on 8/30/13.
//  Copyright (c) 2013 Engineering. All rights reserved.
//

#include <stdio.h>
#include "TheStick.h"


ShapePtr initializeTheStick()
{
    // INITIALIZE GLOBALS
    // Our initial score is 0
    
    // Initialize the struct that represents our ScoreBoard
    StickPtr stickPtr = (StickPtr) malloc(sizeof( TheStick ) );  // Allocates memory for the scoreboard
    
    
    
    
    stickPtr->ShapePtr = initializeTheStick();
    stickPtr->rotate = &rotate;
    
    return stickPtr;
}

void rotate()
{
    return;
}