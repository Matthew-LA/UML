//
//  priority_queue.c
//  COMP1020
//
//  Created by Matthew Lorette Anaya on 4/13/20.
//  Copyright © 2020 Matthew Lorette Anaya. All rights reserved.
//
#include <stdlib.h>
#include "priority_queue.h"

typedef struct couple{
    int priority;
    int value;
}stu;
typedef struct couple Couple;

struct Queue{
    int size;
    int capacity;
    Couple* data;
};
typedef struct Queue Queue;

void up(Couple heap[], int index);
void down(Couple heap[], int index, int size);
void heapit(Couple numbers[], int size);
void heap_sort(Couple numbers[], int size);

void up(Couple heap[], int index)
{
    int index_of_parent;
    index_of_parent = (index - 1)/2;
    Couple temp;
    if (index >= 1 && heap[index].priority > heap[index_of_parent].priority){
        temp = heap[index];
        heap[index] = heap[index_of_parent];
        heap[index_of_parent] = temp;
        up(heap, index_of_parent);
    }
}

void down(Couple heap[], int index, int size)
{
    int index_of_left_child;
    int index_of_right_child;
    index_of_left_child = index * 2 + 1;
    index_of_right_child = index * 2 + 2;
    int index_of_larger_child = size;
    Couple temp;
    
    if (index_of_right_child < size){
        if (heap[index_of_left_child].priority > heap[index_of_right_child].priority){
            index_of_larger_child = index_of_left_child;
            
        }
        else{
            index_of_larger_child = index_of_right_child;
            
        }
    }
    else if (index_of_left_child < size){
        index_of_larger_child = index_of_left_child;
        
    }
    if (index_of_larger_child < size && heap[index_of_larger_child].priority > heap[index].priority){
        temp = heap[index];
        heap[index] = heap[index_of_larger_child];
        heap[index_of_larger_child] = temp;
        down(heap, index_of_larger_child, size);
    }
}

void heapit(Couple numbers[], int size){
    for (int i = (size - 2) / 2; i >= 0; i--){
        down(numbers, i, size);
        
    }
}

void heap_sort(Couple numbers[], int size){
    int temp_size = size;
    Couple temp;
    heapit(numbers, size);
    for (int i = 0; i < size; i++){
        temp = numbers[0];
        numbers[0] = numbers[temp_size - 1];
        numbers[temp_size - 1] = temp;
        temp_size--;
        down(numbers, 0, temp_size);
        
    }
}

PRIORITY_QUEUE priority_queue_init_default(void){
    Queue* pQueue;
    pQueue = (Queue*)malloc(sizeof(Queue));
    if (pQueue != NULL)
    {
        pQueue->size = 0;
        pQueue->capacity = 1;
        pQueue->data = (Couple*)malloc(sizeof(Couple) * pQueue->capacity);
        if (pQueue->data == NULL){
            free(pQueue);
            pQueue = NULL;
            
        }
    }
    return (PRIORITY_QUEUE)pQueue;
}

Status priority_queue_insert(PRIORITY_QUEUE hQueue, int priority_level, int data_item){
    Queue* pQueue = (Queue*)hQueue;
    Couple* temp,temp2;
    int index_of_parent;
    int i;
    if (pQueue->size >= pQueue->capacity){
        temp = (Couple*)malloc(sizeof(Couple) * 2 * pQueue->capacity);
        if (temp == NULL){
            return FAILURE;
        }
        for (i = 0; i < pQueue->size; i++){
            temp[i] = pQueue->data[i];
        }
        pQueue->capacity *= 2;
        free(pQueue->data);
        pQueue->data = temp;
    }
    i = pQueue->size;
    (pQueue->data[i]).priority = priority_level;
    (pQueue->data[i]).value = data_item;
    index_of_parent = (i - 1) / 2;
    while (i >= 1 && ((pQueue->data[i]).priority > (pQueue->data[index_of_parent]).priority)){
        temp2 = pQueue->data[index_of_parent];
        pQueue->data[index_of_parent] = pQueue->data[i];
        pQueue->data[i] = temp2;
        i = index_of_parent;
        index_of_parent = (i - 1) / 2;
    }
    pQueue->size++;
    heapit(pQueue->data,pQueue->size);
    return SUCCESS;
}

Status priority_queue_service(PRIORITY_QUEUE hQueue){
    Queue* pQueue = (Queue*)hQueue;
    Couple temp;
    if (pQueue->size == 0){
        return FAILURE;
        
    }
    temp = pQueue->data[0];
    pQueue->data[0] = pQueue->data[pQueue->size - 1];
    pQueue->data[pQueue->size - 1] = temp;
    pQueue->size--;
    heapit(pQueue->data, pQueue->size);
    return SUCCESS;
}

int priority_queue_front(PRIORITY_QUEUE hQueue, Status* pstatus){
    Queue* pQueue = (Queue*)hQueue;
    if (priority_queue_is_empty(hQueue)){
        if (pstatus != NULL){
            *pstatus = FAILURE;
        }
        return -888;
        
    }
    if (pstatus != NULL){
        *pstatus = SUCCESS;
        
    }
    return pQueue->data[0].value;
}

Boolean priority_queue_is_empty(PRIORITY_QUEUE hQueue){
    Queue* pQueue = (Queue*)hQueue;
    return (Boolean)(pQueue->size == 0);
    
}

void priority_queue_destroy(PRIORITY_QUEUE* phQueue){
    Queue* pQueue = (Queue*)*phQueue;
    free(pQueue->data);
    free(pQueue);
    *phQueue = NULL;
}
