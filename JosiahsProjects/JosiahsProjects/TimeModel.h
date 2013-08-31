//
//  TimeModel.h
//  JosiahsProjects
//
//  Created by User on 8/27/13.
//  Copyright (c) 2013 Engineering. All rights reserved.
//

#ifndef JosiahsProjects_TimeModel_h
#define JosiahsProjects_TimeModel_h


typedef struct
{
    // Updates the time
    void (* updateTime)();
    
    // Gets the current time's seconds
    unsigned char (* getSecond)();
    
    // Gets the current time's minutes
    unsigned char (* getMinute)();
    
    // Free the score model
    void (* free)(void *);
    
} TimeModel, *TimeModelPtr;

TimeModelPtr initializeTimeModel();
#endif
