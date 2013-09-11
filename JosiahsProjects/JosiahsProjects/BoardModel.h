//
//  Board.h
//  JosiahsProjects
//
//  Created by Justin Oliver on 8/22/13.
//  Copyright (c) 2013 Engineering. All rights reserved.
//

#ifndef JosiahsProjects_Board_h
#define JosiahsProjects_Board_h

// The BoardModel is responsible for understanding everything that occurs on the board.

/*
 BoardModel's responsibilities:
 ⁃	falling shape
 ⁃	fall speed
 ⁃	2-dimensional array of chars representing the board
 ⁃	xlen - number of blocks long in x
 ⁃	ylen - number of blocks long in y
 ⁃	fall( )
 ⁃	destroyLine( ) --- moves other li
 ⁃	lockShape( )
 ⁃	interrupt 2: updateBoard( )
*/

 //Example struct:
 // This struct represents the scoreboard
typedef struct
{
    // Updates the score
    void (* updateScore)(int, int);
    
    // Gets the current score
    unsigned long (* getScore)(void);
    
    // Free the score model
    void (* free)(void *);
} ScoreModel, *ScoreModelPtr;



typedef struct
{
    
    void fall()
    {
        return;
    }
    
    void destroyLine()
    {
        return;
    }
    void lockShape()
    {
        return;
    }
    void updateBoard()
    {
        return;
    }

}
// rotate



// move



#endif
