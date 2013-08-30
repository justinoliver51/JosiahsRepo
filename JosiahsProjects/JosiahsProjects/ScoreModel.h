//
//  Header.h
//  JosiahsProjects
//
//  Created by Justin Oliver on 8/21/13.
//  Copyright (c) 2013 Engineering. All rights reserved.
//

#ifndef JosiahsProjects_Header_h
#define JosiahsProjects_Header_h

// This struct represents the scoreboard
typedef struct
{
    // Updates the score
    void (* updateScore)(int, int);
    
    // Gets the current score
    unsigned long (* getScore)(void);
} ScoreModel, *ScoreModelPtr;


// ******** intializeScoreboard **********
// This initializes our scoreboard.
//
// Inputs:    None
//
// Outputs:   None
ScoreModelPtr initializeScoreModel();

#endif
