//
//  main.c
//  JosiahsProjects
//
//  Created by User on 8/8/13.
//  Copyright (c) 2013 Engineering. All rights reserved.
//

#include <stdio.h>
#include "testz.h"
#include "ScoreModel.h"
#include "OpenGL.h"
#include "BoardModel.h"
#include "TheLModel.h"
#include "TheSquareModel.h"
#include "TheSModel.h"

// Function Declarations
void testBoardModel();
void testScoreModel();
void scanfExample();

// Insert point
int main(int argc, const char * argv[])
{
    // Display our game
    //openGLInit(argc, argv);
    
    testBoardModel();
    
    return 0;
}

void testBoardModel()
{
    unsigned int i, j, xLen = 12, yLen = 11;
    
    BoardModelPtr boardModelPtr = initializeBoardModel(xLen, yLen);
    
    for(i = 0, j = 0; i < yLen * 100; i++)
    {
        if(i % xLen == 0)
        {
            // If we have filled the board to the right side, reset back to the left
            if(j >= xLen)
                j = 0;
            
            SquareModelPtr squarePtr = initializeTheSquareModel();
            squarePtr->shapePtr->move(j, yLen);
            boardModelPtr->setFallingShape(squarePtr->shapePtr);  // FIXME: This should be done within updateBoard().  Gets from Preview.
            
            j = j + 2;     // Moves the square 2 spaces to the right
        }
        
        boardModelPtr->updateBoard();
    }
    
    
    return;
}

void testScoreModel()
{
    unsigned long score;
    
    ScoreModelPtr scoreModelPtr = initializeScoreModel();
    
    // Update our score
    scoreModelPtr->updateScore(500000, 2);
    
    // Get our score
    score = scoreModelPtr->getScore();
    
    // Print it
    printf("The score is: %ld", score);
    
    return;
}

void scanfExample()
{
    //char str [80];
    //int i;
    char input;
    /*
    printf ("Enter your family name: ");
    scanf ("%s",str);
    printf ("Enter your age: ");
    scanf ("%d",&i);
    printf ("Mr. %s , %d years old.\n",str,i);
    printf ("Enter a hexadecimal number: ");
    scanf ("%x",&i);
    printf ("You have entered %#x (%d).\n",i,i);
    */
    printf("Enter a character: ");
    scanf("%c", &input);
    
    if(input == 'a')
        printf("Input is 'a'!");
    
    return;
}

// Debug tricks
// p *(*(board + 5) + 0) ===> How to view the coordinate, (5,0)