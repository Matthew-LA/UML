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
 
 Date: 11/29/2019
 Name: Matthew Lorette Anaya
 */
/***********************************************
Author: Matthew
Date: 11/29/2019
Purpose: using functions and file pointers to access files
         to print information to a new file.
Sources of Help: Zybooks
Time Spent: 4 hours
***********************************************/
#include <stdio.h>
#include <ctype.h>

void Get_Name(FILE*, FILE*);
void Get_Score(FILE*, FILE*);

int main(int argc, char* argv[]){
   FILE* inFile = NULL;
   FILE* outFile = NULL;
   
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
   
   while (!feof(inFile)){
      Get_Name(inFile, outFile);
   }
   
   fclose(inFile);
   fclose(outFile);
   
   return 0;
}
void Get_Name(FILE* in, FILE* out){
  char   name;
  char   readName[50];
  char   fName[50];
  char   lName[50];
  char   fullName[50];
  int    nameRead;
  int    numChar = 0;
  int    i = 0;
  int    j = 0;
  int    blank = 0;
  int    counter = 0;
  
  //reading name from file and storing it in name
  //then storing name in a string named readName
  while ((nameRead = fscanf(in, "%c", &name)) == 1){
      if(name == '\n'){
         readName[numChar] = '\0';
         numChar++;
         break;
      }
      else if(isblank(name)){
         blank++;
      }
      else if(blank == 2){ //if blank counter hits 2 end of name.
         readName[numChar] = '\0';
         break;
      }
      readName[numChar] = name;
      numChar++;
      counter++;
   
   }
   fseek(in, -1L, SEEK_CUR); //move back one postion.
   
   //reseting counter to be used in next loop
   //to find the end of the first and last names.
   blank = 0;
   //loop to separate first and last names.
   while (i < numChar){
      if(readName[i] == ' ' && blank != 1){
         fName[i] = '\0';
         blank++;
         i++;
      }
      else if(blank == 0){ //if blank is 0 start of first name.
         fName[i] = readName[i];
         i++;
      }
      else if(blank == 1){ //if blank is 1 start of last name.
         if(i == (numChar - 1)){// if i is 1 less than string length end last name with comma and space.
            lName[j] = ',';
            lName[j+1] = ' ';
            lName[j+2] = '\0';
            break;
         }
         lName[j] = readName[i];
         i++;
         j++;
      }
   }

   //reseting counter variables
   i = 0;
   j = 0;
   //loop placing the last name in fullName first
   while(lName[i] != '\0'){
      fullName[i] = lName[i];
      i++;
   }
   //loop placing first name in fullName after last.
   while(fName[j] != '\0'){
      fullName[i] = fName[j];
      i++;
      j++;
   }
   fullName[i] = '\0';
   //print name to file.
   fprintf(out,"%-20s", fullName);
   
   //get score for just read name function call.
   Get_Score(in, out);
}
void Get_Score(FILE* in, FILE* out){
   int    num;
   int    sum = 0;
   int    numOfNum = 0;
   double average;
   
   //loop to read in scores.
   while (fscanf(in, "%d", &num) == 1){
       sum+= num;
       numOfNum++;
      fprintf(out, "%4d", num);
   }
   average = (double)sum / 10.0;
   
   //loop if there are less than 10 scores and print to file.
   while (numOfNum != 10){
      fprintf(out,"%4d", 0);
      numOfNum++;
   }
   //print average to end of scores and end with new line.
   fprintf(out,"%10.2f", average);
   fprintf(out,"\n");
   
}
