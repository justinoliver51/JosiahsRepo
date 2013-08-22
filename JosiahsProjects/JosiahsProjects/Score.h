//
//  Header.h
//  JosiahsProjects
//
//  Created by Justin Oliver on 8/21/13.
//  Copyright (c) 2013 Engineering. All rights reserved.
//

#ifndef JosiahsProjects_Header_h
#define JosiahsProjects_Header_h


/*  How scoring is determined in tetris, where n is the current level:
 
 Points for 1 line:
 40 * (n + 1)

 Points for 2 lines:
 100 * (n + 1)	 
 
 Points for 3 lines:
 300 * (n + 1)	 
 
 Points for 4 lines:
 1200 * (n + 1)

*/

/*
// This struct represents the scoreboard
typedef struct
{
    // The player's current score
    unsigned int score;
    
    // Updates the score
    void (* updateScoreBoard)(int, int);
} ScoreBoard;
 */

// The player's current score
unsigned int score;


// Initializes the scoreboard
void initializeScoreboard();


// Updates the scoreboard
void updateScoreBoard(int, int, long);

#endif
