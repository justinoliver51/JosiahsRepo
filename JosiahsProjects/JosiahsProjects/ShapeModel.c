//
//  ShapeModel.c
//  JosiahsProjects
//
//  Created by User on 8/30/13.
//  Copyright (c) 2013 Engineering. All rights reserved.
//

#include <stdio.h>
#include "ShapeModel.h"


#define NUMBER_OF_BLOCKS 4

// the state is the position of the blocks for that shape
static unsigned int state;

// color is the color of the blocks that make up the shape
// legal colors: blue = 'b', green = 'g',  red = 'r',  orange = 'o'
static unsigned char color;

// this is the array containing the locations for each of our blocks
static Location positionarray[NUMBER_OF_BLOCKS];



void rotate()
{
    return;
}


ShapePtr initializeShape()
{
    // INITIALIZE GLOBALS
    // Our initial score is 0
    state = 0;
    color = 'b';
    
    // Initialize the struct that represents our ScoreBoard
    ShapePtr shapePtr = (ShapePtr) malloc(sizeof( Shape ) );  // Allocates memory for the scoreboard
    
    
    return shapePtr;
}
