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
 
 Date: 10/04/2019
 Name: Matthew Lorette Anaya
 */
/***********************************************
Author: Matthew Lorette Anaya
Date: 10/04/2019
Purpose: The use of nested loops in if else statements
Sources of Help: Zybooks

Time Spent: 15 mins
***********************************************/
#include <stdio.h>
int main(int argc, char* argv[]){
   
   double sum = 0,
          average = 1,
          numOfInput = 0,
          input;
   
   printf("Enter a positive score (0 or negative to quite):\n");
   scanf("%lf", &input);
   
   if (input > 0){
      while (input > 0){
         numOfInput += 1;
         sum += input;
         printf("Enter a positive score (0 or negative to quite):\n");
         scanf("%lf", &input);
      }
   average = sum / numOfInput;
   printf("The sum is: %.2lf, average is: %.2lf\n", sum, average);
   }
   else if (input <= 0){
      printf("No sum and average calculated!");
   }
   
   
   return 0;
}
      
   
