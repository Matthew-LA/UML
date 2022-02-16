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
 
 Date: 10/30/2019
 Name: Matthew Lorette Anaya
 */

/***********************************************
    Author: Matthew Lorette Anaya
    Date: 10/30/2019
 
    Purpose: familiarizing with temp variables and swapping of
             such.
 
    Sources of Help: Zybooks
 
    Time Spent: 30 mins
 ***********************************************/

#include <stdio.h>
void orderThree(double*, double*, double*);


int main(int argc, char * argv[]) {
    double num1, num2, num3;
    
    printf("Enter three numbers separated by blanks:\n");
    scanf("%lf%lf%lf", &num1, &num2, &num3);
    
    orderThree(&num1, &num2, &num3);

    
    
    //Display the Results
    printf("The numbers in ascending order are: %.2f %.2f %.2f\n", num1, num2, num3);
    
    return 0;
}

void orderThree(double *val1, double *val2, double *val3){
   double temp;
   
   while (*val1 > *val2 || *val1 > *val3 || *val2 > *val3){
      if (*val1 > *val2){
         temp = *val1;
         *val1 = *val2;
         *val2 = temp;
      }
      else if (*val1 > *val3){
         temp = *val1;
         *val1 = *val3;
         *val3 = temp;
      }
      else if (*val2 > *val3){
         temp = *val2;
         *val2 = *val3;
         *val3 = temp;
      }
      else if (*val2 > *val1){
         temp = *val2;
         *val2 = *val1;
         *val1 = temp;
      }
      else if (*val3 > *val1){
         temp = *val3;
         *val3 = *val1;
         *val1 = temp;
      }
      else if (*val3 > *val2){
         temp = *val3;
         *val3 = *val2;
         *val2 = temp;
      }
   }
}
   
 
      
