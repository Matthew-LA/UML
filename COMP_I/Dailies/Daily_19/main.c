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
 
 Date: 11/01/2019
 Name: Matthew Lorette Anaya
 */
 /***********************************************
Author: Matthew Lorette Anaya
Date: 11/01/2019
Purpose: creating an array and reversing the elements.
Explanation: Using int temp as a place holder for the first value in
arr, then equating that first value with the last, and equating the last
with the first by using the temp value. iterating upwards from the beginning
and downwards form the end. until the middle is reached. Only have to iterate
half of arr because we are swapping two values with one iteration.
Sources of Help: Zybooks
Time Spent: 30mins
***********************************************/
#include <stdio.h>

int main(int argc, char *argv[]){
   int arr[40];
   int temp;
   char ast = '*';
   
   //initializing arr with values.
   for (int i = 0; i < 40; i++){
      arr[i] = i * 3;
   }
   //Printing the values in arr.
   for (int i = 0; i < 40; i++){
      printf("%7d", arr[i]);
      if ((i+1) % 10 ==0){
         printf("\n");
      }
   }
   //Print asterisk seperation.
   for (int i = 0; i < 5; i++){
      printf("%c", ast);
   }
   printf("\n");
   
   //Reversing values in arr.
   for (int i = 0; i < (40 / 2); i++){
      temp = arr[i];
      arr[i] = arr[40 - 1 - i];
      arr[40 - 1 - i] = temp;
   }
   //Print arr in reverse order.
   for (int i = 0; i < 40; i++){
      printf("%7d", arr[i]);
      if ((i+1) % 10 ==0){
         printf("\n");
      }
   }
      
   return 0;
}
