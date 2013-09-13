//
//  ShapeModel.h
//  JosiahsProjects
//
//  Created by User on 8/28/13.
//  Copyright (c) 2013 Engineering. All rights reserved.
//

#ifndef JosiahsProjects_ShapeModel_h
#define JosiahsProjects_ShapeModel_h

#define NUMBER_OF_BLOCKS 4

typedef struct
{
    unsigned long x;
    unsigned long y;
} Location, *LocationPtr;

typedef struct
{
    // FUNCTIONS
    // Moves the 
    void (* move)(int, int);
    
    // Rotates the position of the blocks for a shape
    void (* rotate)();
    
    unsigned int (* getState)();
    
    void (* setState)(int);
    
    // Free the score model
    void (* free)(void *);
    
    // Returns a copy of the position array of the specific shape
    void (* getPositionArray)(LocationPtr);


} ShapeModel, *ShapeModelPtr;


// Functions
ShapeModelPtr initializeShapeModel();

#endif
