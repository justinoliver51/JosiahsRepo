//
//  PreviewModel.h
//  JosiahsProjects
//
//  Created by User on 10/18/13.
//  Copyright (c) 2013 Engineering. All rights reserved.
//

#ifndef JosiahsProjects_PreviewModel_h
#define JosiahsProjects_PreviewModel_h
#include "ShapeModel.h"
// ******** getNextShape **********
// Adds a new shape to the previews array.
//
// Inputs:    None
//
// Outputs:   Shapemodelptr pointing to the new shape
ShapeModelPtr getNextShape();

// ******** update **********
// Decides if we need a new shape and if we do, then it calls getNextShape.
//
// Inputs:    None
//
// Outputs:   None
void update();

//if this variable is set to 0, do nothing, if its set to 1 it will add a new shape to the preview model
int updatePreviewFlag;


#endif
