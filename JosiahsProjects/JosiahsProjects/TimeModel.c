//
//  TimeModel.c
//  JosiahsProjects
//
//  Created by User on 8/27/13.
//  Copyright (c) 2013 Engineering. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "TimeModel.h"

unsigned char second;
unsigned char minute;

void updateTime()
{
    second = second + 1;
    
    if(second == 60)
    {
        second = 0;
        minute = minute + 1;
    }
    return;
}

unsigned char getSecond()
{
    return second;
}

unsigned char getMinute()
{
    return minute;
}

// Frees the allocated memory of the Score Model
void freeTimeModel(void *timeModel)
{
    TimeModelPtr timeModelPtr = (TimeModelPtr) timeModel;
    free(timeModelPtr);
}


TimeModelPtr initializeTimeModel()
{
    // INITIALIZE GLOBALS
    second = 0;             // seconds are initially zero
    minute = 0;             // minutes are initially zero
    
    // Initialize the struct that represents our ScoreBoard
    TimeModelPtr timeModelPtr = (TimeModelPtr) malloc(sizeof( TimeModel ) );  // Allocates memory for the scoreboard
    
    timeModelPtr->updateTime = &updateTime;
    timeModelPtr->getSecond = &getSecond;
    timeModelPtr->getMinute = &getMinute;
    timeModelPtr->free = &freeTimeModel;
    
    return timeModelPtr;
}