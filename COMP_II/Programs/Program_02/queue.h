//
//  queue.h
//  COMP1020
//
//  Created by Matthew Lorette Anaya on 3/6/20.
//  Copyright © 2020 Matthew Lorette Anaya. All rights reserved.
//
#ifndef queue_h
#define queue_h


typedef void* QUEUE;

Car* new_node(int l);
Car_Queue *create_car_queue();
void add_to_car_queue(Car_Queue *q, int l);
int check(Car_Queue *l, Car_Queue *r);
void remove_cars(Car_Queue *q, int l)

#endif
