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
}

unsigned char getMinute()
{
    return minute;
}