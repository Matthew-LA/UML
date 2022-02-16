/*
 Computing I -- COMP.1010 Honor Statement
 
 The practice of good ethical behavior is essential for maintaining
 good order in the classroom, providing an enriching learning
 experience for students, and as training as a practicing computing
 professional upon graduation.  This practice is manifested in the
 University's Academic Integrity policy. Students are expected to
 strictly avoid academic dishonesty and adhere to the Academic
 Integrity policy as outlined in the course catalog.  Violations
 will be dealt with as outlined therein.
 
 All programming assignments in this class are to be done by the
 student alone.  No outside help is permitted except the instructor
 and approved tutors.
 
 I certify that the work submitted with this assignment is mine and
 was generated in a manner consistent with this document, the
 course academic policy on the course website on Blackboard, and
 the UMass Lowell academic code.
 
 Date: 10//22/2019
 Name: Matthew Lorette Anaya
 */
 /***********************************************
Author: Matthew Lorette Anaya
Date: 10/22/2019
Purpose: To become familiar with using stub function
Sources of Help: Zybooks
Time Spent: 20mins
***********************************************/

#include <stdio.h>

void convert_lengths(void);
void convert_weights(void);

int main(int argc, char *argv[]){
   int choice;
   
   do{
      printf("1. convert lenghts\n");
      printf("2. convert weights\n");
      printf("0. Exit\n");
      printf("Please choose from (1, 2, 0):\n");
      scanf("%d", &choice);
   
      switch (choice){
      
         case 1:
            convert_lengths();
            break;
         
         case 2:
            convert_weights();
            break;
         
         case 0:
            printf("User chose to exit.\n");
            break;
      }
   }while (choice != 0);
   
   return 0;
}

// Stub function for converting lengths.
void convert_lengths(void){
   printf("The user wants to convert_lengths.\n");
}
// Stub functon for converting weights.
void convert_weights(void){
   printf("The user wants to convert_weights.\n");
}
