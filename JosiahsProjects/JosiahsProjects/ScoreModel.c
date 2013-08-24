//
//  Score.c
//  JosiahsProjects
//
//  Created by Justin Oliver on 8/21/13.
//  Copyright (c) 2013 Engineering. All rights reserved.
//

#include <stdio.h>
#include "ScoreModel.h"

// The player's current score
static unsigned long score;

// Updates the scoreboard
void updateScoreBoard(int, int);

// Returns the current score
unsigned long getScore();

// ******** intializeScoreboard **********
// This initializes our scoreboard.
//
// Inputs:    None
//
// Outputs:   None
ScoreBoardPtr initializeScoreboard()
{
    // INITIALIZE GLOBALS
    // Our initial score is 0
    score = 0;
    
    // Initialize the struct that represents our ScoreBoard
    ScoreBoardPtr scoreBoardPtr = (ScoreBoardPtr) malloc(sizeof( ScoreBoard ) );  // Allocates memory for the scoreboard
    scoreBoardPtr->updateScoreBoard = &updateScoreBoard;
    scoreBoardPtr->getScore = &getScore;

    return scoreBoardPtr;
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
    
    return;
}

unsigned long getScore()
{
    return score;
}