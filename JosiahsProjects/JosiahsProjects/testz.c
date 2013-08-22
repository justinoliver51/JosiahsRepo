//
//  testz.c
//  JosiahsProjects
//
//  Created by User on 8/15/13.
//  Copyright (c) 2013 Engineering. All rights reserved.
//

#include <stdio.h>
#include "arrays.h"
#include "strings.h"

void testStringLength()
{
    int temp;
    char str[] = {'a', 'b', 'c', 'd', '\0'};
    
    temp = stringlength(str);
    printf("The string is '%s'\nThe length is %d", str, temp);
    
    return;
}
void testsortArray()
{
    int temp;
    int arr[5] = {5, 2, 7, 4, 5};
    int len = 5;
    
    temp = *sortArray(arr, len);
    
    printIntegerArray(arr, len);
    
    return;
}
void testarrayMaximum()
{
    ArrayList list;
    int max;
    
    list.arr[0] = 5;
    list.arr[1] = 4;
    list.arr[2] = 2;
    list.arr[3] = 6;
    list.arr[4] = 7;
    list.len = 5;
    
    max = arrayMaximum(list);
    
    printf("%d, ", max);  // could have also printed max
}
