//
//  queue.c
//  COMP1020
//
//  Created by Matthew Lorette Anaya on 3/6/20.
//  Copyright © 2020 Matthew Lorette Anaya. All rights reserved.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "queue.h"

typedef struct car Car;
struct car{
    int length;
    Car *next;
};

typedef struct car_queue{
    Car *front;
    Car *rear;
} Car_Queue;

Car* new_node(int l){

    Car *temp = (Car*)malloc(sizeof(Car));
    temp->length = l;
    temp->next = NULL;
    return temp;
}

Car_Queue *create_car_queue(){

    Car_Queue *q = (Car_Queue*)malloc(sizeof(Car_Queue));
    q->front = q->rear = NULL;
    return q;
}

void add_to_car_queue(Car_Queue *q, int l){
    Car *temp = new_node(l);

    if (q->rear == NULL){
        q->front = q->rear = temp;
        return;
    }

    q->rear->next = temp;
    q->rear = temp;
}

int check(Car_Queue *l, Car_Queue *r){

    if( l->front == NULL && r->front == NULL){
        return 1;
    }

    return 0;
}

void remove_cars(Car_Queue *q, int l){
    int sum=0;
    if(q->front == NULL){
        return;
    }
    
    while(q->front != NULL){
        sum = sum + q->front->length;
        if(sum>l*100){
            break;
        }
        q->front = q->front->next;
    }
   
    if (q->front == NULL){
        q->rear = NULL;
    }
  
}
