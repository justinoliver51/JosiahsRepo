//
//  ShapeModel.c
//  JosiahsProjects
//
//  Created by User on 8/30/13.
//  Copyright (c) 2013 Engineering. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "ShapeModel.h"

// FUNCTION DECLARATIONS
void freeShapeModel(void *shapeModel);
unsigned int getState();
void setState(int);

// PRIVATE VARIABLES
// The position of the blocks for that shape
static unsigned int state;

// color is the color of the blocks that make up the shape
// legal colors: blue = 'b', green = 'g',  red = 'r',  orange = 'o'
static unsigned char color;

ShapeModelPtr initializeShapeModel()
{
    // INITIALIZE GLOBALS
    state = 0;      // Our initial state is 0
    color = 'b';    // Our initial color is blue
    
    // Initialize the struct that represents our ScoreBoard
    ShapeModelPtr shapePtr = (ShapeModelPtr) malloc(sizeof( ShapeModel ) );  // Allocates memory for the scoreboard
    
    shapePtr->free = &freeShapeModel;
    shapePtr->getState = &getState;
    shapePtr->setState = &setState;
    
    return shapePtr;
}

// Accessor for color
unsigned int getColor()
{
    return color;
}

// Setter for color


// Accessor for state
unsigned int getState()
{
    return state;
}

// Setter for state
void setState(int newState)
{
    state = newState;
}

// Frees the allocated memory of the Score Model
void freeShapeModel(void *shapeModel)
{
    ShapeModelPtr shapeModelPtr = (ShapeModelPtr) shapeModel;
    free(shapeModelPtr);
}