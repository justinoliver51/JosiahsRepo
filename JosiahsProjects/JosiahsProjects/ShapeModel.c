//
//  ShapeModel.c
//  JosiahsProjects
//
//  Created by User on 8/30/13.
//  Copyright (c) 2013 Engineering. All rights reserved.
//

#include <stdio.h>
#include "ShapeModel.h"

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
    
    return shapePtr;
}

// Accessor for color


// Setter for color


// Accessor for state


// Setter for state


// Accessor for the positionArray