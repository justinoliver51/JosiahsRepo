
//
//  Board.h
//  JosiahsProjects
//
//  Created by Justin Oliver on 8/22/13.
//  Copyright (c) 2013 Engineering. All rights reserved.
//

#ifndef JosiahsProjects_Board_h
#define JosiahsProjects_Board_h

#include "ShapeModel.h"

// The BoardModel is responsible for understanding everything that occurs on the board


typedef struct
{
    //makes shapes fall down the board 1 space
    int (* fall)();
    
    //gets rid of a line when cubes occupy the entire line
    void (* destroyLines)();
    
    //prevents user from being able to rotate the shape
    char (* lockShape)();
    
    //called by an interrupt when its time to update the state of the board
    void (* updateBoard)();
    
    // Setter for the falling shape
    void (* setFallingShape)(ShapeModelPtr);
    
    // finds the line for the destroy line function
    int (* findFilledLine)();
    
} BoardModel, *BoardModelPtr;


// ******** intializeBoardModel **********
// This initializes our boardModel.
//
// Inputs:    None
//
// Outputs:   None

BoardModelPtr initializeBoardModel(unsigned int xLen, unsigned int yLen);

#endif