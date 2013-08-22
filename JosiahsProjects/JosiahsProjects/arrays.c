
//
//  arrays.c
//  JosiahsProjects
//
//  Created by User on 8/15/13.
//  Copyright (c) 2013 Engineering. All rights reserved.
//

#include <stdio.h>
#include "arrays.h"

// ******** function_name **********
// Description of function
//
// Inputs:    type input1
//
// Outputs:   type output1

//sup
int* reverseArray(int arr[],int len)
{
    int temp;
    int i;
    int m = len - 1;
    
    for(i = 0; i < m; i = i + 1, m = m - 1)
    {
        temp = arr[i];
        arr[i] = arr[m];
        arr[m] = temp;
    }
    
    return arr; //[5,4,3,2,1]
}

void printIntegerArray(int arr[], int len)
{
    int i = 0;  // This is the index or counter
    
    for(i = 0; i < len; i = i + 1)
    {
        printf("%d, ", arr[i]);
    }
    
    printf("\n");
    
    return;
}

// ******** sortArray **********
// Takes an array and its length,
// sorts it from low to high, and
// returns a pointer to the array
//
// Inputs:    int arr[] - the array to be sorted
//            int len - the length of the array
//
// Outputs:   int *sortedArray

int* sortArray(int arr[], int len)
{
    int i = 0;
    int m = 1;
    int temp;
    int didswap = 1;
    
    while(1)
    {
        i = 0;
        m = 1;
        didswap = 0;

        for(i = 0; i < len && m < len; i = i + 1, m = m + 1)
        {
            printIntegerArray(arr, len);
            
            if( arr[i] > arr[m])
            {
                didswap = 1;
                temp = arr[i];
                arr[i] = arr[m];
                arr[m] = temp;
            }

        }
        if( didswap == 0)
        {
            return arr;
        }
    }
    
    return arr;
}

// ******** arrayMaximum **********
// Takes struct and finds its max
//  
//
// Inputs:    ArrayList list
//
// Outputs:   max

int arrayMaximum(ArrayList list)
{
    int i = 0;
    int max = 0;
    for( i = 0; i < list.len; i = i + 1)
    {
        printIntegerArray(list.arr, list.len);
        
        // it checks if the memory location temp in arr is less than the new one
        if( list.arr[i] > max)
        {
            max = list.arr[i];
        }
    }
    
    return max;
}



