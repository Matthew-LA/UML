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
 
 Date: 10/06/2019
 Name: Matthew Lorette Anaya
 */
 /***********************************************
Author: Matthew Lorette Anaya
Date: 10/06/2019
Purpose: to use the Collatz conjecture formula to find how many steps
it takes to take a number down to 1. From one starting point to an
ending point.
Sources of Help: Zybooks

Time Spent: 2 hours
***********************************************/
#include <stdio.h>

//function prototypes
void clear_keyboard_buffer(void);
int get_start_number(int);
int get_end_number(int, int);
void oneness(int, int);

int main(int arc, char* argv[]){
   int startInput, endInput;
   int startPoint, endPoint;
   
   //starting point validation function call
   printf("Enter a starting point:\n");
   scanf("%d", &startInput);
   clear_keyboard_buffer();
   startPoint = get_start_number(startInput);
   
   //ending point validation function call
   printf("Enter an ending point:\n");
   scanf("%d", &endInput);
   clear_keyboard_buffer();
   endPoint = get_end_number(endInput, startPoint);
   
   //Collatz Conjecture function call
   oneness(startPoint, endPoint);
   
   
   return 0;
}
//function validating starting point (2 to 99)
int get_start_number(int startInput){
   int startNumber = startInput;
   
   if (startNumber <= 1 || startNumber >= 100){
      while(startNumber <= 1 || startNumber >= 100){
         printf("Enter a valid starting point (from 2 - 99):\n");
         scanf("%d", &startNumber);
         clear_keyboard_buffer();
      }
      return startNumber;
   }
   else{
      return startNumber;
   }
}
//function validating end point (start point +1 to 999)
int get_end_number(int endInput, int startPoint){
   int endNumber = endInput;
   int startNumber = startPoint;
   
   if (endNumber >= 1000 || endNumber <= startNumber){
      while(endNumber >= 1000 || endNumber <= startNumber){
         printf("Enter a valid ending point (from %d - 999):\n", startNumber + 1);
         scanf("%d", &endNumber);
         clear_keyboard_buffer();
      }
      return endNumber;
   }
   else{
      return endNumber;
   }
}
//function Collatz conjecture
void oneness(int startPoint, int endPoint){
   int startNum = startPoint;
   int endNum = endPoint;
   int count = 0;
   int column = 0;
   
   while (startPoint != endNum +1){
      while (startNum != 1 ){
         if (startNum % 2 == 0){
            startNum /= 2;
            count++;
         }
         else{
         startNum = startNum * 3 + 1;
         count++;
         }
      }
      //proper formatting called by program outline
      column++;
      if (column % 7 == 0){
      printf("%5d:%-5d\n", startPoint, count);
      startPoint++;
      startNum = startPoint;
      count = 0;
      }
      else{
         printf("%5d:%-5d", startPoint, count);
      startPoint++;
      startNum = startPoint;
      count = 0;
      }
   }
   
}
//function clearing uneccessary inputs
void clear_keyboard_buffer(void){
 char ch;
 scanf("%c", &ch);
 while (ch != '\n' && ch != '\0') {
 scanf("%c", &ch);
 }
}

