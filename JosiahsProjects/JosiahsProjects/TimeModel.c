//
//  TimeModel.c
//  JosiahsProjects
//
//  Created by User on 8/27/13.
//  Copyright (c) 2013 Engineering. All rights reserved.
//

#include <stdio.h>
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
}*

unsigned char getMinute()
{
    return minute;
}

TimeBoardPtr initializetimeboard()
{
    // INITIALIZE GLOBALS
    // Our initial score is 0
    second = 0;
    minute = 0;
    
    // Initialize the struct that represents our ScoreBoard
    TimeBoardPtr timeBoardPtr = (TimeBoardPtr) malloc(sizeof( TimeBoard ) );  // Allocates memory for the scoreboard
    timeBoardPtr->updateTime = &updateTime;
    timeBoardPtr->getSecond = &getSecond;
    timeBoardPtr->getMinute = &getMinute;

    
    return timeBoardPtr;
}
