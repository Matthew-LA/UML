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
 
 Date: 11/18/2019
 Name: Matthew Lorette Anaya
 */
 /***********************************************
Author: Matthew Lorette Anaya
Date: 11/18/2019
Purpose: familiarizing with files and char practice
Sources of Help: Zybooks
Time Spent: 40 mins
***********************************************/
#include <stdio.h>
#include <ctype.h>

int main(int argc, char* argv[]){
   FILE* inFile = NULL;
   FILE* outFile = NULL;
   char name;
   int numOfCon,numOfName, num;
   int blank = 0;
   int numOfNums = 0;
   int sum = 0;
   double average;
   
   inFile = fopen("quiz.txt", "r");
   outFile = fopen("average.txt", "w");
   
   if (inFile == NULL) {
      printf("Could not open file quiz.txt.\n");
      return -1;
   }
   else if (outFile == NULL) {
      printf("Could not open file average.txt.\n");
      return -1;
   }
   //while loop to read name
   while(!feof(inFile)){
      numOfName = fscanf(inFile, "%c", &name);
         if (numOfName == 1){
            //if statement after name is read to start reading numbers
            if (isblank(name)){
               ++blank;
            }
            else if (blank == 1){
               //while loop to start reading numbers from file after name has been read
               while(!feof(inFile)){
                  numOfCon = fscanf(inFile, "%d", &num);
                  if (numOfCon == 1){
                     sum += num;
                     //printing numbers to average.txt file
                     fprintf(outFile, "%4d", num);
                     numOfNums++;
                  }
                  else{
                     break;
                  }
               }
            }
            else{
               continue;
            }
         }
         else{
            break;
         }
   }
   //average arithmatic
   average = (double)sum / 10.0;
   fclose(inFile);
   
   //loop for when there are less than 10 scores
   while (numOfNums != 10){
      fprintf(outFile, "%4d", 0);
      numOfNums++;
   }
   //write average to file after all test scores
   fprintf(outFile, "%10.2f", average);
   fclose(outFile);
   
   return 0;
}
