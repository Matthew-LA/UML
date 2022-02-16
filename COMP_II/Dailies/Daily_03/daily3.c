//
//  daily3.c
//  COMP1020
//
//  Created by Matthew Lorette Anaya on 4/22/20.
//  Copyright © 2020 Matthew Lorette Anaya. All rights reserved.
//
/***********************************************************
Author: Matthew Lorette Anaya
Date: 02/03/2020
Effort: 10mins
Purpose: familiarizing with the left shift operator
***********************************************************/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv [])
{
    unsigned int x = 1;
    int i;
    
    for(i = 0; i < 32; i++){
        printf("%u: %u\n", i, x<<i);
    }
    return 0;
}
 



