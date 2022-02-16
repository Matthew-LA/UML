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
 
 Date: 09/30/2019
 Name: Matthew Lorette Anaya
 */
/***********************************************
Author: Matthew Lorette Anaya
Date: 09/30/2019
Purpose: To use a while loop to trap incorrect input until it is correct and
print chars with a function call.
Sources of Help: Zybooks

Time Spent: 15 mins
***********************************************/
#include <stdio.h>

void clear_keyboard_buffer (void);
void draw_line (char, int);

int main(int argc, char* argv[]){
   char chDraw;
   int numDraw;
   
   printf("Please enter the character you want to draw:\n");
   scanf(" %c", &chDraw);
   printf("Please enter the number of characters you want in your line:\n");
   scanf("%d", &numDraw);
   
   while ((numDraw < 1) || (numDraw > 79)){
      printf("I'm sorry, that number is unrecognized or out of range, try [1-79]:\n");
      scanf("%d", &numDraw);
      clear_keyboard_buffer ();
   }
   
   draw_line (chDraw, numDraw);
   
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
void draw_line (char symbol, int numOfPrint){
   for (int i = 0; i < numOfPrint; i++){
      printf("%c", symbol);
   }
   printf("\n");
}
