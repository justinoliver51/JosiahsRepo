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
    ShapeModelPtr shapePtr;
    
    // Free the score model
    void (* free)(void *);
} TheStickModel, *StickModelPtr;

/*
 
 State 0
 y
        ___ ___ ___ ___
       |   |   |   |   |
     4 |   |   |   | O |
       |___|___|___|___|
       |   |   |   |   |
     2 |   |   |   | O |
       |___|___|___|___|
       |   |   |   |   |
     1 |   |   |   | O |
       |___|___|___|___|
       |   |   |   |   |
     0 |   |   |   | O |
       |___|___|___|___|
     
     0   1   2   3    x
     
     
     
     State 1
     y
        ___ ___ ___ ___
       |   |   |   |   |
     4 |   |   |   |   |
       |___|___|___|___|
       |   |   |   |   |
     2 |   |   |   |   |
       |___|___|___|___|
       |   |   |   |   |
     1 |   |   |   |   |
       |___|___|___|___|
       |   |   |   |   |
     0 | 0 | 0 | 0 | O |
       |___|___|___|___|
     
     0   1   2   3    x
 
 */


#endif
