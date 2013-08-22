//
//  strings.c
//  JosiahsProjects
//
//  Created by User on 8/15/13.
//  Copyright (c) 2013 Engineering. All rights reserved.
//

#include <stdio.h>

#define null '\0'

// ******** function_name **********
// Description of function
//
// Inputs:    type input1 - short description
//
// Outputs:   type output1 - sh desc


// ******** stringLength **********
// Takes a string, returning the length
// but not including the NULL character
//
// Inputs:    char str - string
//
// Outputs:   int len - length of string
int stringlength(char str[])
{

    int i;
    
    for(i = 0; str[i] != null; i = i + 1){}
    
    // i is the length because it counts how many times it went through the loop
    
    return i;
}

// ******** stringCompare **********
// Takes two strings and compares them
//returns 0 if theyre equal and 1 if not
//
// Inputs:    char str1[] - string 1
//            char str2[] - string 2
//
// Outputs:   0 - returns 0 if they are equal
//            1 - returns 1 if they aren't equal
int stringCompare(char str1[], char str2[])
{
    int i;
    
    for(i = 0; str1[i] != null || str2[i] != null; i = i + 1)
    {
        if(str1[i] != str2[i])
        {
            return 1;
        }
    }
    return 0;
}

