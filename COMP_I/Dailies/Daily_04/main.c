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
 
 Date: 09/12/2019
 Name: Matthew Lorette Anaya
 */
 /***********************************************
Author: Matthew
Date: 09/12/2019
Purpose: This program familiarizes the use of place holders in the printf function.
Sources of Help: Zybook
Time Spent: 10 mins
***********************************************/

#include <stdio.h>

int main(int argc, char* argv[]){
   printf("%d is an integer and should be printed using %%d.\n\n", 57);
   printf("The character '%c' can be printed using %%c.\n\n", '%');
   printf("Floating point numbers use %%f. %f is an example.\n\n", 3.141590);
   printf("Using placeholder %%%.1ff can display the value of %c number to an accuracy %s.\n", 5.2, 'a', "of two decimal places");
   
   return 0;
}
