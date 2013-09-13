//
//  ShapeModel.h
//  JosiahsProjects
//
//  Created by User on 8/28/13.
//  Copyright (c) 2013 Engineering. All rights reserved.
//

#ifndef JosiahsProjects_ShapeModel_h
#define JosiahsProjects_ShapeModel_h

typedef struct
{
    unsigned long x;
    unsigned long y;
} Location;

typedef struct
{
    void (* move)(int, int);
    
    // Rotates the position of the blocks for a shape
    void (* rotate)();
    
    unsigned int (* getState)();
    
    void (* setState)(int);
    
    // Free the score model
    void (* free)(void *);
    


} ShapeModel, *ShapeModelPtr;

ShapeModelPtr initializeShapeModel();

#endif
