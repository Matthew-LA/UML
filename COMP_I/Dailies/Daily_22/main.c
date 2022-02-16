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
 
 Date: 11/08/2019
 Name: Matthew Lorette Anaya
 */
 /***********************************************
Author: Matthew Lorette Anaya
Date: 11/08/2019
Purpose: familiarizing with files and fscanf
Sources of Help: Zybooks
Time Spent: 30mins
***********************************************/
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]){
   FILE* inFile = NULL;
   int numOfCon, num;
   int sum = 0;
   int numOfNums = 0;
   int temp;
   int largest = -9999999;
   int smallest = 0;
   double average;
   
   inFile = fopen("numbers.txt", "r");
   if (inFile == NULL){
      printf("Could not open numbers.txt");
      return -1;
   }
   while(!feof(inFile)){
      numOfCon = fscanf(inFile, "%d", &num);
      if (numOfCon == 1){
         numOfNums += numOfCon;
         sum += num;
         temp = num;
         if (num > largest){
            largest = temp;
         }
         if (num < smallest){
            smallest = num;
         }
      }
   }
   average = sum / (double)numOfNums;
   fclose(inFile);
   
   printf("There were %d numbers in the file.\n", numOfNums);
   printf("The sum of all the integers in the file is %d.\n", sum);
   printf("The smallest integer in the file is %d.\n", smallest);
   printf("The largest integer in the file is %d.\n", largest);
   printf("The average of all the numbers is %f.\n", average);
      
   return 0;
}
