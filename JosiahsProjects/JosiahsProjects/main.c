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


// Function Declarations
void testScoreBoard();
void scanfExample();

// Insert point
int main(int argc, const char * argv[])
{
    // Display our game
    openGLInit(argc, argv);
    
    return 0;
}


void testScoreBoard()
{
    unsigned long score;
    
    ScoreBoardPtr scoreBoardPtr = initializeScoreboard();
    
    // Update our score
    scoreBoardPtr->updateScoreBoard(500000, 2);
    
    // Get our score
    score = scoreBoardPtr->getScore();
    
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