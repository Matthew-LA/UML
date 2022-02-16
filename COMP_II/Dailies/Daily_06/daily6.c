/***********************************************************
Author: Matthew Lorette Anaya
Date: 02/16/2020
Effort: 30mins
Purpose: Familiarizing with bitwise operands
***********************************************************/
#include <stdio.h>

void set_flag(unsigned int flag_holder[], int flag_position);
void unset_flag(unsigned int flag_holder[], int flag_position);
int check_flag(unsigned int flag_holder[], int flag_position);
void display_32_flags_as_array(unsigned int flag_holder);
void display_flags(unsigned int flag_holder[], int size);

int main(int argc, char* argv[])
{
    unsigned int flag_holder[5] = { 0 };
    set_flag(flag_holder, 3);
    set_flag(flag_holder, 16);
    set_flag(flag_holder, 31);
    set_flag(flag_holder, 87);
    display_flags(flag_holder, 5);

    printf("\n\n");

    unset_flag(flag_holder, 31);
    unset_flag(flag_holder, 3);
    set_flag(flag_holder, 99);
    set_flag(flag_holder, 100);
    display_flags(flag_holder, 5);

    return 0;
}
//Function for setting flag
void set_flag(unsigned int flag_holder[], int flag_position)
{
    int bit = 1 << flag_position;
    flag_position /= 32;
    flag_holder[flag_position] |= bit;
}
//Function for unsetting flag
void unset_flag(unsigned int flag_holder[], int flag_position)
{
    int bit_to_set = flag_position;
    flag_position /= 32;
    flag_holder[flag_position] &= ~(1 << (bit_to_set % 32));
}
//Function for flag checking
int check_flag(unsigned int flag_holder[], int flag_position)
{
    int bit;
    int bit_to_set = flag_position;
    flag_position /= 32;
    if((flag_holder[flag_position] >> bit_to_set) & 1){
        bit = 1;
    }
    else{
        bit = 0;
    }
    return bit;
}
//Function to display the flag as array
void display_32_flags_as_array(unsigned int flag_holder)
{
    int i =  0;
    while(i <= 31){
        printf("%d", check_flag(&flag_holder, i));
        i++;
        if(i % 4 == 0){
            printf(" ");
        }
    }
    printf("\n");
}
//Function to display flag
void display_flags(unsigned int flag_holder[], int size)
{
   int i;
   for (i = 0; i < size; i++) {
       //Function calling
       display_32_flags_as_array(flag_holder[i]);
   }
    printf("\n");
}



