//
//  TheStick.h
//  JosiahsProjects
//
//  Created by User on 8/30/13.
//  Copyright (c) 2013 Engineering. All rights reserved.
//

#ifndef JosiahsProjects_TheStick_h
#define JosiahsProjects_TheStick_h

#include "ShapeModel.h"

typedef struct
{
    ShapePtr shape;
    // this function rotates the position of the blocks for a shape
    void (* rotate)();
} TheStick, *StickPtr;


#endif
