//
//  arrays.h
//  JosiahsProjects
//
//  Created by User on 8/15/13.
//  Copyright (c) 2013 Engineering. All rights reserved.
//

#ifndef JosiahsProjects_arrays_h
#define JosiahsProjects_arrays_h

int* reverseArray(int arr[],int len);
void printIntegerArray(int arr[], int i);
int* sortArray(int arr[], int len);

typedef struct {
    int len;
    int arr[5];
}ArrayList;

int arrayMaximum(ArrayList list);

#endif