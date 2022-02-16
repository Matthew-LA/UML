/***********************************************************
Author: Matthew Lorette Anaya
Date: 02/21/2020
Effort: 5h
Purpose: create a container
Interface proposal: In my case, i would say a display function.
 I myself like to see the manipulation in action, especially during tests.
***********************************************************/
#include <stdlib.h>
#include <stdio.h>
#include "bit_flags.h"

struct bit_flags{
    int size;
    int capacity;
    unsigned int* bits;
};
typedef struct bit_flags Bit_flags;

BIT_FLAGS bit_flags_init_number_of_bits(int number_of_bits){
    
    int i;
    Bit_flags* pBit_flags;
    
    if(number_of_bits > 0){
        
        pBit_flags = (Bit_flags*)malloc(sizeof(Bit_flags));
    
        if(pBit_flags != NULL){
            pBit_flags->capacity = 32;
            pBit_flags->size = number_of_bits;
        
            while(number_of_bits >= pBit_flags->capacity){
                pBit_flags->capacity += 32;
            }
    
            pBit_flags->bits = (unsigned int*)malloc(sizeof(unsigned int) * pBit_flags->capacity);
            
            if(pBit_flags == NULL){
                free(pBit_flags);
                pBit_flags = NULL;
            }
            for(i = 0; i < pBit_flags->size; i++){
                pBit_flags->bits[i] = 0;
            }
        }
    }
    else{
        printf("Number of bits must be positive.\n");
        pBit_flags = NULL;
        }
    return pBit_flags;
}

Status bit_flags_set_flag(BIT_FLAGS hBit_flags, int flag_position){
    
    int i;
    unsigned int* temp;
    Bit_flags* pBit_flags = (Bit_flags*)hBit_flags;
    
    while(flag_position >= pBit_flags->capacity){
        temp = (unsigned int*)malloc(sizeof(unsigned int) * (pBit_flags->capacity + 32));
        if(temp == NULL){
            return FAILURE;
        }
        
        for(i = 0; i < pBit_flags->size; i++){
            temp[i] = pBit_flags->bits[i];
        }
        
        free(pBit_flags->bits);
        pBit_flags->bits = temp;
        pBit_flags->capacity += 32;
    }
    if(flag_position >= pBit_flags->size){
        pBit_flags->size = flag_position + 1;
    }
    pBit_flags->bits[flag_position/32] |= (1 << flag_position);
    
    return SUCCESS;
}

Status bit_flags_unset_flag(BIT_FLAGS hBit_flags, int flag_position){
   
    int i;
    unsigned int* temp;
    Bit_flags* pBit_flags = (Bit_flags*)hBit_flags;
    
    while(flag_position >= pBit_flags->capacity){
        temp = (unsigned int*)malloc(sizeof(unsigned int) * (pBit_flags->capacity + 32));
        if(temp == NULL){
            return FAILURE;
        }
        for(i = 0; i < pBit_flags->size; i++){
            temp[i] = pBit_flags->bits[i];
        }
        
        free(pBit_flags->bits);
        pBit_flags->bits = temp;
        pBit_flags->capacity += 32;
    }
    if(flag_position >= pBit_flags->size){
        pBit_flags->size = flag_position + 1;
    }
    pBit_flags->bits[flag_position/32] &= ~(1 << flag_position);
    
    return SUCCESS;
}

int bit_flags_check_flag(BIT_FLAGS hBit_flags, int flag_position){
    
    int bit = 0;
    int bit_to_set = flag_position;
    Bit_flags* pBit_flags = (Bit_flags*)hBit_flags;
    
    if(flag_position < 0 || flag_position > pBit_flags->capacity){
        bit = -1;
    }
    else{
        flag_position /= pBit_flags->capacity;
        if((pBit_flags->bits[flag_position] >> bit_to_set) & 1){
            bit = pBit_flags->bits[flag_position];
        }
    }
    return bit;
}

int bit_flags_get_size(BIT_FLAGS hBit_flags){
    
    Bit_flags* pBit_flags = (Bit_flags*)hBit_flags;
    return (pBit_flags->size);
}

int bit_flags_get_capacity(BIT_FLAGS hBit_flags){
    
    Bit_flags* pBit_flags = (Bit_flags*)hBit_flags;
    return (pBit_flags->capacity);
}

void bit_flags_destroy(BIT_FLAGS* phBit_flags){
    
    Bit_flags* pBit_flags = (Bit_flags*)*phBit_flags;
    free(pBit_flags->bits);
    free(pBit_flags);
    
    *phBit_flags = NULL;
}
