//
//  daily2.c
//  COMP1020
//
//  Created by Matthew Lorette Anaya on 4/22/20.
//  Copyright © 2020 Matthew Lorette Anaya. All rights reserved.
//
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int highest_num(int*, int);
int main(int argc, char* argv [])
{
    int* arr;
    int n;
    int maxElement;
    int i;
    
    srand(time(NULL));
    printf("Input the size of array\n");
    scanf("%d", &n);
    
    arr = (int*)malloc(sizeof(int) * n);
    
    for (i = 0; i < n; i++){
        arr[i] = rand() % 100;
    }
    
    for (i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    maxElement = highest_num(arr, n);
    printf("%d", maxElement);
    
    free(arr);
    
    return 0;
}
int highest_num(int* pt, int size){
    int number = pt[0];
    int element = 0;
    int i;
    
    for (i = 0; i <= size - 1; i++){
        if(number < pt[i]){
            number = pt[i];
            element = i;
        }
    }
    return element;
}
