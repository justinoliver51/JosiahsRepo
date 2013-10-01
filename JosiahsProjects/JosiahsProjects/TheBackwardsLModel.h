//
//  TheBackwardsLModel.h
//  JosiahsProjects
//
//  Created by User on 8/30/13.
//  Copyright (c) 2013 Engineering. All rights reserved.
//

#ifndef JosiahsProjects_TheBackwardsLModel_h
#define JosiahsProjects_TheBackwardsLModel_h

#include "ShapeModel.h"

typedef struct
{
    ShapeModelPtr shapePtr;
    
    // Free the score model
    void (* free)(void *);
} TheBackwardsLModel, *BackwardsLModelPtr;

// Initialize the T Model
BackwardsLModelPtr initializeTheBackwardsLModel();

/*
 State 0
     y
        ___ ___ ___ 
       |   |   |   |
     2 |   |   | 3 |
       |___|___|___|
       |   |   |   |
     1 |   |   | 2 |
       |___|___|___|
       |   |   |   |
     0 |   | O | 1 |
       |___|___|___|
 
         0   1   2     x
 

 State 1
      y
        ___ ___ ___ 
       |   |   |   |
     2 |   |   |   |
       |___|___|___|
       |   |   |   |
     1 | 2 |   |   |
       |___|___|___|
       |   |   |   |
     0 | 3 | 0 | 1 |
       |___|___|___|
 
         0   1   2     x

 
 State 2
     y
        ___ ___ ___ 
       |   |   |   |
     2 | O | 1 |   |
       |___|___|___|
       |   |   |   |
     1 | 2 |   |   |
       |___|___|___|
       |   |   |   |
     0 | 3 |   |   |
       |___|___|___|
 
         0   1   2     x
 
 
 State 3
     y
        ___ ___ ___ 
       |   |   |   |
     2 |   |   |   |
       |___|___|___|
       |   |   |   |
     1 | 2 | 0 | 1 |
       |___|___|___|
       |   |   |   |
     0 | 3 |   |   |
       |___|___|___|
 
         0   1   2     x
*/


#endif
