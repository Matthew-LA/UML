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
Purpose: To familiarize with loops and if else in a function
call with a buffer clear.
Sources of Help: Zybooks
Time Spent: 10 mins
***********************************************/

#include <stdio.h>

void clear_keyboard_buffer(void);

int main(int argc, char* argv[]){
   
   int input;
   
   printf("Please enter a negative number:\n");
   scanf("%d", &input);
   
   if (input >= 0){
      while (input >= 0){
         printf("I'm sorry, you must enter a negative integer less than zero:\n");
         clear_keyboard_buffer();
         scanf("%d", &input);
      }
   }
      printf("I got the number %d!\n", input);
   
   
   return 0;
}

void clear_keyboard_buffer(void)
{
 char ch;
 scanf("%c", &ch);
 while (ch != '\n' && ch != '\0') {
 scanf("%c", &ch);
 }
}
         


