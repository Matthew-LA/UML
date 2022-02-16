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
 
 Date: 09/23/2019
 Name: Matthew Lorette Anaya
 */
/***********************************************
Author: Matthew Lorette Anaya
Date: 09/23/2019
Purpose: To call a function in main to print three smiley faces.

 Main difference from the previous version: The main difference
 with this program is we are using a for loop to make a function call
 within main to print the smiley faces. With the previous program we used
 numerous printf statements within main to do so.
Sources of Help: Zybooks

Time Spent: 10 minutes
***********************************************/

#include <stdio.h>

void smileFace(void);

int main(int argc, char* argv[]){
   int callCount = 3;
   
   for (int i = 0; i < callCount; i++){
      if ( i < 2){
      smileFace();
      printf("\n");
      }
      else{
         smileFace();
      }
   }
   
   return 0;
}
void smileFace(void){
   printf("  ****\n");
   printf(" * . .*\n");
   printf("*      *\n");
   printf("*  \\_/ *\n");
   printf(" *    *\n");
   printf("  ****\n");
}
