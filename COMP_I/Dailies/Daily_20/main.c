/***********************************************
 Computing I -- COMP.1010 Honor Statement
 
 The practice of good ethical behavior is essential for maintaining good order in the classroom, providing an enriching learning experience for students, and as training as a practicing computing professional upon graduation.  This practice is manifested in the University's Academic Integrity policy. Students are expected to strictly avoid academic dishonesty and adhere to the Academic Integrity policy as outlined in the course catalog.  Violations will be dealt with as outlined therein.
 
 All programming assignments in this class are to be done by the student alone.  No outside help is permitted except the instructor and approved tutors.
 
 I certify that the work submitted with this assignment is mine and was generated in a manner consistent with this document, the course academic policy on the course website on Blackboard, and the UMass Lowell academic code.
 
 Date: 11/04/2019
 Name: Matthew Lorette Anaya
 ***********************************************/
 /***********************************************
Author: Matthew Lorette Anaya
Date: 11/04/2019
Purpose: finding pairs within an array
Explanation: Since we are comparing the previous index with the following
             we are starting at index = 0 the bounds must be two less than
             the size of the array as to not go over when adding the +1 to
             the following index. IE if the size is 3 the bounds must be i < 3 -1.
             That way when i becomes 2 it will break the loop as to not cause an error
             when comparing it to the next i (i + 1) because that would make i = 3 and
             that would make it an illegal array index.
Sources of Help: Zybooks
Time Spent: 20 mins
***********************************************/

#include <stdio.h>

int findIdenticalPair(double*, int);

int main(int argc, char * argv[]) {
    double arr[10] = { 1.2, 6.1, 3.3, 3.1, 4.5, 7.9, 5.6, 5.4, 9.9, 1.0};
    
    int index = 0;
    
    //call the function to get the index
    index = findIdenticalPair(arr, 10);
    
    printf("index is: %d\n", index);
    
    return 0;
}
int findIdenticalPair(double* array, int SIZE){
   int pair = 0;
   
   for(int i = 0; i < SIZE - 1; i++){
      if (array[i] == array[i + 1]){
         pair = i;
         break;
      }
      else{
         pair = -1;
      }
   }
   return pair;
}
