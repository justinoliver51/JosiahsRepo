//
//  PreviewModel.c
//  JosiahsProjects
//
//  Created by User on 10/18/13.
//  Copyright (c) 2013 Engineering. All rights reserved.
//

#include <stdio.h>
#include "PreviewModel.h"
#include "ShapeModel.h"
#include "TheZModel.h"

ShapeModelPtr getNewShape();

// this variable sets how long the bottom length of the board is, (horizontal)
static unsigned int xLen;

// this variable sets how long the side length of the board is, (vertical)
static unsigned int yLen;

// this is the  that contains the shapes that are going to be previewed next
static ShapeModelPtr shapeArray;

// ******** update **********
// Decides if we need a new shape and if we do, then it calls getNextShape.
//
// Inputs:    None
//
// Outputs:   None
void update()
{
    //checking to see if we need to update, if 0 then do nothing, if 1 then update
    if(updatePreviewFlag == 0)
    {
        return;
    }
    
    //removing the third shape and changing the others to the one after it
    shapeArray[0] = shapeArray[1];
    shapeArray[1] = shapeArray[2];
    //the reason there is a star here is because we need the value of getNewShape not the location
    shapeArray[2] = *getNewShape();
    
    //shapeArray[0] = (ShapeModelPtr) NULL;
    
    // before we call get next shape remove the first shape
    // move up the next 2 shapes
     
    return;
}

// ******** getNewShape **********
// Add a new shape
//
// Inputs:    None
//
// Outputs:   ShapeModelPtr

ShapeModelPtr getNewShape()
{
    ZModelPtr b = initializeTheZModel();
    
    //fixme: make it randomly choose any shape
    
    return b->shapePtr;
}


/*
TimeModelPtr initializeTimeModel()
{
    // INITIALIZE GLOBALS
    
     updatePreviewFlag = 0;
 
    // Initialize the struct that represents our ScoreBoard
    TimeModelPtr timeModelPtr = (TimeModelPtr) malloc(sizeof( TimeModel ) );  // Allocates memory for the scoreboard
    
    timeModelPtr->updateTime = &updateTime;
    timeModelPtr->getSecond = &getSecond;
    timeModelPtr->getMinute = &getMinute;
    timeModelPtr->free = &freeTimeModel;
    
    return timeModelPtr;
}
*/