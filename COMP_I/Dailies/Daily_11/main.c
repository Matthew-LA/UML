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
 
 Date: 10/02/2019
 Name: Matthew Lorette Anaya
 */
 /***********************************************
Author: Matthe Lorette Anaya
Date: 10/02/2019
Purpose: familiarizing with the use of nesting
Sources of Help: Zybooks
Time Spent: 15 mins
***********************************************/

#include <stdio.h>
int main(int argc, char* argv[]){
   char player1;
   char player2;
   
printf("Player-1, please enter your choice <p>aper, <r>ock, or <s>cissors:\n");
scanf(" %c", &player1);
   
printf("Player-2, please enter your choice <p>aper, <r>ock, or <s>cissors:\n");
scanf(" %c", &player2);
   
   if ((player1 == 'P') || (player1 == 'p')){
      if ((player2 == 'P') || (player2 == 'p')){
         printf("Draw, nobody wins.\n");
      }
      else if ((player2 == 'R') || (player2 == 'r')){
         printf("Player-1 wins! Paper covers rock!\n");
      }
      else if ((player2 == 'S') || (player2 == 's')){
         printf("Player-2 wins! Scissors cut paper!\n");
      }
   }
   else if ((player1 == 'R') || (player1 == 'r')){
      if ((player2 == 'P') || (player2 == 'p')){
         printf("Player-2 wins! Paper covers rock!\n");
      }
      else if ((player2 == 'R') || (player2 == 'r')){
          printf("Draw, nobody wins.\n");
      }
      else if ((player2 == 'S') || (player2 == 's')){
         printf("Player-1 wins! Rock breaks scissors!\n");
      }
   }
   else if ((player1 == 'S') || (player1 == 's')){
       if ((player2 == 'P') || (player2 == 'p')){
          printf("Player-1 wins! Scissors cut paper!\n");
       }
       else if ((player2 == 'R') || (player2 == 'r')){
          printf("Player-2 wins! Rock breaks scissors!\n");
       }
       else if ((player2 == 'S') || (player2 == 's')){
          printf("Draw, nobody wins.\n");
       }
   }
   
   return 0;
}
       
          
       
      
         
      
         

