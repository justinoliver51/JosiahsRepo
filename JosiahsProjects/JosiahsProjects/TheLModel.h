//
//  TheLModel.h
//  JosiahsProjects
//
//  Created by User on 8/30/13.
//  Copyright (c) 2013 Engineering. All rights reserved.
//

#ifndef JosiahsProjects_TheLModel_h
#define JosiahsProjects_TheLModel_h

#include "ShapeModel.h"

typedef struct
{
    ShapeModelPtr shapePtr;
    
    // Free the score model
    void (* free)(void *);
} TheLModel, *LModelPtr;

// Initialize the L Model
LModelPtr initializeTheLModel();

/*
 State 0
     y
        ___ ___ ___ 
       |   |   |   |
     2 | 3 |   |   |
       |___|___|___|
       |   |   |   |
     1 | 2 |   |   |
       |___|___|___|
       |   |   |   |
     0 | 0 | 1 |   |
       |___|___|___|
 
         0   1   2     x
 

 State 1
      y
        ___ ___ ___ 
       |   |   |   |
     2 |   |   |   |
       |___|___|___|
       |   |   |   |
     1 | 2 | 3 | 1 |
       |___|___|___|
       |   |   |   |
     0 | 0 |   |   |
       |___|___|___|
 
         0   1   2     x

 
 State 2
     y
        ___ ___ ___ 
       |   |   |   |
     2 | 1 | 2 |   |
       |___|___|___|
       |   |   |   |
     1 |   | 3 |   |
       |___|___|___|
       |   |   |   |
     0 |   | 0 |   |
       |___|___|___|
 
         0   1   2     x
 
 
 State 3
     y
        ___ ___ ___ 
       |   |   |   |
     2 |   |   |   |
       |___|___|___|
       |   |   |   |
     1 |   |   | 1 |
       |___|___|___|
       |   |   |   |
     0 | 2 | 0 | 3 |
       |___|___|___|
 
         0   1   2     x
*/


#endif
