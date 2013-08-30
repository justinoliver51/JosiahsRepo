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
    
    // Gets the current time
    unsigned char (* getSecond)();
    
    unsigned char (* getMinute)();
    
} TimeModel, *TimeModelPtr;

TimeModelPtr initializeTimeModel();
#endif
