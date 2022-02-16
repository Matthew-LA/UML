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
 
 Date: 10/11/2019
 Name: Matthew Lorette Anaya
 */
 /***********************************************
Author: Matthew Lorette Anaya
Date: 10/11/2019
Purpose: using functions
Sources of Help: Zybooks

Time Spent: 20 mins
***********************************************/

#include <stdio.h>

int getInt1(void);
int getInt2(void);
int getGCD(int, int);

int main(int argc, char *argv[]){
   int num1, num2, ans;
   
  num1 = getInt1();
  num2 = getInt2();
   
   ans = getGCD(num1, num2);
   printf("The largest integer that divides both %d and %d is: %d\n", num1, num2, ans);
   
   return 0;
}

int getInt1(void){
   int input;
   
   printf("Please enter a positive integer:\n");
   scanf("%d", &input);
   
   if (input <= 0){
      while (input <= 0){
         printf("I'm sorry, that number is unrecognized or not positive.\n");
         printf("Please enter a positive integer:\n");
         scanf("%d", &input);
      }
      return input;
   }
   else{
   return input;
   }
}
int getInt2(void){
   int input;
   
   printf("Please enter a second positive integer:\n");
   scanf("%d", &input);
   
   if (input <= 0){
      while (input <= 0){
         printf("I'm sorry, that number is unrecognized or not positive.\n");
         printf("Please enter a positive integer:\n");
         scanf("%d", &input);
      }
      return input;
   }
   else{
   return input;
   }
}

int getGCD(int num1, int num2){
   int input1 = num1;
   int input2 = num2;
   
   if (input1 > input2){
      while (!(input1 % input2 == 0) || !(num2 % input2 == 0)){
         input2--;
      }
      return input2;
   }
   else if (input2 > input1){
      while (!(input2 % input1 == 0) || !(num1 % input1 == 0)){
         input1--;
      }
      return input1;
   }
   else{
      return num1;
   }
}
         
   
