//
//  Score.c
//  JosiahsProjects
//
//  Created by Justin Oliver on 8/21/13.
//  Copyright (c) 2013 Engineering. All rights reserved.
//

#include <stdio.h>
#include "Score.h"



// ******** function_name **********
// Description of function
//
// Inputs:    type input1 - short description
//
// Outputs:   type output1 - sh desc




// ******** intializeScoreboard **********
// This initializes our scoreboard.
//
// Inputs:    None
//
// Outputs:   None
void initializeScoreboard()
{
    score = 0;
    
    return;
}


// ******** updateScoreBoard **********
// This function updates the scoreboard.
//
// Inputs:    int level - the current level
//            int lines - number of lines destroyed
//
// Outputs:   None
void updateScoreBoard(int level, int lines)
{
    if(lines == 1)
    {
        score = 40 * (level + 1) + score;
    }
    else if(lines == 2)
    {
        score = 100 * (level + 1) + score;
    }
    else if(lines == 3)
    {
        score = 300 * (level + 1) + score;
    }
    else
    {
        score = 1200 * (level + 1) + score;
    }
    
    printf("%d, ", score);
    
    return;
}