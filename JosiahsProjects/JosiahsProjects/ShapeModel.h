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
    void (* initializeShape)();
} Shape, *ShapePtr;


#endif
