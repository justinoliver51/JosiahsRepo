//
//  TheSquareModel.h
//  JosiahsProjects
//
//  Created by User on 8/30/13.
//  Copyright (c) 2013 Engineering. All rights reserved.
//

#ifndef JosiahsProjects_TheSquareModel_h
#define JosiahsProjects_TheSquareModel_h

#include "ShapeModel.h"

typedef struct
{
    ShapeModelPtr shapePtr;
    
    // Free the score model
    void (* free)(void *);
} TheSquareModel, *SquareModelPtr;

/*
 

 
 */


#endif
