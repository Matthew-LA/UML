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
 
 Date: 09/25/2019
 Name: Matthew Lorette Anaya
 */

/***********************************************
Author: Matthew Lorette Anaya
Date: 09/25/2019
Purpose: becoming familiar with the use of while
loop function calls.
Sources of Help: Zybooks
Time Spent: 10 mins
***********************************************/

#include <stdio.h>

void loop_down_to_zero(int);
void loop_up_to_zero(int);

int main(int argc, char* argv[]){
   
   int input;
   
   printf("Please enter a positive number.\n");
   scanf("%d", &input);
   loop_down_to_zero(input);
   printf("****\n");
   loop_up_to_zero(input);
   
   return 0;
}

void loop_down_to_zero(int num){
   while (num >= 0){
      printf("%d\n", num);
      num -= 1;
   }
}
void loop_up_to_zero(int num){
   int i = 0;
   while ( i <= num){
      printf("%d\n", i);
      i += 1;
   }
}
      
   

   
   
