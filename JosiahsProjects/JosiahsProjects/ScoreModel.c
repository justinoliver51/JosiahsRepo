//
//  Score.c
//  JosiahsProjects
//
//  Created by Justin Oliver on 8/21/13.
//  Copyright (c) 2013 Engineering. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "ScoreModel.h"

// The player's current score
static unsigned long score;

// Updates the score
void updateScore(int, int);

// Returns the current score
unsigned long getScore();

// Frees the allocated memory of the Score Model
void freeScoreModel(void *);

// ******** intializeScoreboard **********
// This initializes our scoreboard.
//
// Inputs:    None
//
// Outputs:   None
ScoreModelPtr initializeScoreModel()
{
    // INITIALIZE GLOBALS
    // Our initial score is 0
    score = 0;
    
    // Initialize the struct that represents our ScoreBoard
    ScoreModelPtr scoreModelPtr = (ScoreModelPtr) malloc(sizeof( ScoreModel ) );  // Allocates memory for the scoreboard
    scoreModelPtr->updateScore = &updateScore;
    scoreModelPtr->getScore = &getScore;
    scoreModelPtr->free = &freeScoreModel;

    return scoreModelPtr;
}

// ******** updateScoreBoard **********
// This function updates the scoreboard.
//
// Inputs:    int level - the current level
//            int lines - number of lines destroyed
//
// Outputs:   None
void updateScore(int level, int lines)
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

// Frees the allocated memory of the Score Model
void freeScoreModel(void *scoreModel)
{
    ScoreModelPtr scoreModelPtr = (ScoreModelPtr) scoreModel;
    free(scoreModelPtr);
}