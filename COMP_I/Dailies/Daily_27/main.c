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
 
 Date: 12/11/2019
 Name: Matthew Lorette Anaya
 */
 /***********************************************
Author: Matthew Lorette Anaya
Date: 12/11/2019
Purpose: uses the malloc function to dynamically allocate the
         designated amount memory for an array and sotring
         variabeles within it.
Sources of Help: Zybooks
 Time Spent: 30mins
***********************************************/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]){
   int   n;
   int   *ptArr;
   
   printf("Please enter the number of elements of your dynamic array: ");
   scanf("%d", &n);
   
   while(n <= 0){
      printf("Invalid input please enter a valid number.\n");
      printf("Please enter the number of elements of your dynamic array: ");
      scanf("%d", &n);
   }
   
   ptArr = (int*)malloc(sizeof(int));
   
   for(int i = n - 1; i >= 0; i--){
      ptArr[i] = i + 1;
      printf("Element at index %d : %d\n", i, ptArr[i]);
   }
   
   printf("***\n");
   
   for(int j = 0; j < n; j++){
      printf("Element at index %d : %d\n", j, *(ptArr + j));
   }
   for(int j = 0; j < n; j++){
      *ptArr -= j;
   }
   
   //free(ptArr);
   
   return 0;
}
