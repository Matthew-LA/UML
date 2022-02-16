/***********************************************************
Author: Matthew Lorette Anaya
Date: 02/10/2020
Effort: 1h
Purpose: Familiarizing with bitwise operands
***********************************************************/
#include <stdio.h>
void set_flag(unsigned int* flag_holder, int flag_position);
void unset_flag(unsigned int * flag_holder, int flag_position);
int check_flag(unsigned int flag_holder, int flag_position);
void display_32_flags(unsigned int flag_holder);

int main(int argc, char* argv[])
{
    unsigned int flag_holder = 0;
    set_flag(&flag_holder, 3);
    set_flag(&flag_holder, 16);
    set_flag(&flag_holder, 31);
    
    display_32_flags(flag_holder);
    
    unset_flag(&flag_holder, 31);
    unset_flag(&flag_holder, 3);
    set_flag(&flag_holder, 9);
    
    display_32_flags(flag_holder);
    return 0;
}
void set_flag(unsigned int* flag_holder, int flag_position)
{
    int bit = 1 << flag_position;
    *flag_holder = *flag_holder | bit;
}
void unset_flag(unsigned int * flag_holder, int flag_position)
{
    int bit_to_set = flag_position;
    flag_position /= 32;
    flag_holder[flag_position] &= ~(1 << (bit_to_set % 32));
}
int check_flag(unsigned int flag_holder, int flag_position)
{
    int n = 1 << flag_position;
    int bit = flag_holder & n;
    if(bit == 0){
        return 0;
    }
    else{
        return 1;
    }
}
void display_32_flags(unsigned int flag_holder)
{
    int i;
    for(i = 31; i >= 0; i--){
        printf("%d", check_flag(flag_holder, i));
        if(i % 4 == 0){
            printf(" ");
        }
    }
    printf("\n");
}





