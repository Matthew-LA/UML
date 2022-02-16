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
 
 Date: 11/20/2019
 Name: Matthew Lorette Anaya
 */
/***********************************************
Author: Matthew Lorette Anaya
Date: 11/20/2019
Purpose: reading char input from the keyboard into a string
         and using a function to reverse it.
 Sources of Help: Zybooks>
 Time Spent: 40 mins
***********************************************/
#include <stdio.h>

char* reverseString(char*);

int main(int argc, char* argv[]){
   char string[81];
   char input;
   int i = 0;
   
   printf("Please enter a string:\n");
   while(input != '\n' && i < 80){
      scanf("%c", &input);
      if (input == '\n'){
         break;
      }
      string[i] = input;
      i++;
   }
   string[i] = '\0';
   printf("%s\n", string);
   
   
   reverseString(string);
   printf("%s\n", string);
   
   return 0;
}
char* reverseString(char* reverse){
   char* start;
   char* end;
   int length, temp;
   int l = 0;
   
   while (reverse[l] != '\0'){
      l++;
   }
   length = l;
   
   start = reverse;
   end = reverse;
   
   for(l = 0; l < length - 1; l++){
      end++;
   }

   for(l = 0; l < length / 2; l++){
      temp = *end;
      *end = *start;
      *start = temp;
      start++;
      end--;
   }
   return reverse;
}
      
