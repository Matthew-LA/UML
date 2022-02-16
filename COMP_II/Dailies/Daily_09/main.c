//
//  main.c
//  COMP1020
//
//  Created by Matthew Lorette Anaya on 4/13/20.
//  Copyright © 2020 Matthew Lorette Anaya. All rights reserved.
//

/**********************************************************************
 Program: Daily 9
 Author: Matthew Lorette Anaya
 Date: April 13
 Time spent: 10  hours
 Purpose: Practice the implementation of queues
 ***********************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "priority_queue.h"


int main(int argc, char* argv[]){
    
    PRIORITY_QUEUE hQueue = NULL;
    hQueue = priority_queue_init_default();
   
    if (hQueue == NULL){
        printf("failed to creat new queue\n");
        exit(1);
    }
    priority_queue_insert(hQueue, 55, 1);
    priority_queue_insert(hQueue, 10, 2);
    priority_queue_insert(hQueue, 56, 3);
    priority_queue_insert(hQueue, 8, 4);
    priority_queue_insert(hQueue, 200, 5);
    priority_queue_insert(hQueue, 88, 6);
 
    while (priority_queue_is_empty(hQueue) != TRUE){
        printf("%d\n", priority_queue_front(hQueue, NULL));
        priority_queue_service(hQueue);
    }
    priority_queue_destroy(&hQueue);
}
