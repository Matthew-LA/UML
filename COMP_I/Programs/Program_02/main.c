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
 
 Date: 10/27/2019
 Name: Matthew Lorette Anaya
 */
 /***********************************************
Author: Matthew Lorette Anaya
Date: 10/27/2019
Purpose: using Fibonacci sequence to find the green crud population.
Sources of Help: Zybooks
Time Spent: 1 hour
***********************************************/

#include <stdio.h>

int Crud_Validate(void);
int Day_Validate(void);
void clear_keyboard_buffer(void);
void Green_Crud_Pop(int, int);

int main(int argc, char *argv[]){
   int crudWeight, days;
   char choice;
   
   //Function calls within do while loop to continue
   //if user wants choose yes.
   do{
      crudWeight = Crud_Validate();
      days = Day_Validate();
      Green_Crud_Pop(crudWeight, days);
      printf("Would you like to continue?\n");
      scanf(" %c", &choice);
   }while ( choice == 'y' || choice == 'Y');
      
   return 0;
}
//Crud weight validation function. initializing input to a negative
//number to ensure while loop, if an invalid char is used and cleared.
int Crud_Validate(void){
   int input= -999;
   
   printf("Please enter the initial size of the green crud:\n");
   scanf(" %d", &input);
   
   
   while (input < 0){
      clear_keyboard_buffer();
      printf("I'm sorry that value is unrecognized or is negative.\n");
      printf("Please enter the initial size of the green crud:\n");
      scanf(" %d", &input);
      }
   return input;

}
//Number of days validation function. initializing days to a negative
//number to ensure while loop, if an invalid char is used and cleared.
int Day_Validate(void){
   int days = -999;
   
   printf("Please enter the number of days:\n");
   scanf("%d", &days);
   
   while (days < 0){
      clear_keyboard_buffer();
      printf("I'm sorry that value is unrecognized or is negative.\n");
      printf("Please enter the number of days:\n");
      scanf(" %d", &days);

   }
   return days;
}
//Fibonacci function to print the population after weight and days
//are inputed. days = numDays / 5 to ensure the iteration of every
//fifth day.
void Green_Crud_Pop(int weight, int numDays){
   int population = 0;
   int i;
   int days = numDays / 5;
   int temp = 0;
   
   if (numDays > 5 && weight > 0){
      for (i = 1; i <= days; i++){
         population = weight + temp;
         temp = weight;
         weight = population;
      }
      printf("The final population would be %d pounds.\n", population);
   }
   else{
      printf("The final population would be %d pounds.\n", weight);
   }
   
   
}
//Clear keyboard buffer function.
void clear_keyboard_buffer(void){
 char ch;
 scanf("%c", &ch);
 while (ch != '\n' && ch != '\0') {
   scanf("%c", &ch);
 }
}
