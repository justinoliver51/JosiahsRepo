//
//  main.c
//  JosiahsProjects
//
//  Created by User on 8/8/13.
//  Copyright (c) 2013 Engineering. All rights reserved.
//

#include <stdio.h>

// Function Declarations
int* arrayReverse(int arr[],int len);
void printIntegerArray(int arr[], int i);

// Insert point
int main(int argc, const char * argv[])
{
    int arr233[] = {5,8,2,9,7,1};
    int *arr1;
    int len = 6;
    
    
    arr1 = arrayReverse(arr233,len);
    
    
    printIntegerArray(arr1, len);
           
    return 0;
}

int *arrayReverse(int arr[],int len)
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
    
    return;
}