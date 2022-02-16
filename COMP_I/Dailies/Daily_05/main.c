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
 
 Date: 09/16/2019
 Name: Matthew Lorette Anaya
 */
 /***********************************************
Author: Matthew Lorette Anaya
Date: 09/16/2019
Purpose: Familiarize with the use of variables and arithmetic opperands
Sources of Help: Zybooks

Time Spent: <Insert how much time you spent
on the assignment here>
***********************************************/

#include <stdio.h>

int main (int argc, char* argv[]){
   // (1)
   int num1 = 100;
   int num2 = 10;
   int num3 = 16;
   int num4 = 4;
   int sum, product, quotient, remainder;
   
   // (2)
   printf("The first number is: %d\n", num1);
   printf("The second number is: %d\n", num2);
   printf("The third number is: %d\n", num3);
   printf("The last number is: %d\n\n", num4);
   
   // (3.a)
   sum = num1 + num2;
   printf("The sum of 100 and 10 is: %d\n", sum);
   
   // (3.b)
   product = num1 * num3;
   printf("The product of 100 and 16 is: %d\n", product);
   
   // (3.c)
   quotient = num2 / num4;
   printf("The quotient of 10 divided by 4 is: %d\n", quotient);
   
   // (3.d)
   remainder = num1 % num4;
   printf("The remainder of 100 divided by 4 is: %d\n", remainder);
   
   
 
 return 0;
}
