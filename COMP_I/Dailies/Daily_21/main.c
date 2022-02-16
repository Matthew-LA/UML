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
 
 Date: 11/06/2019
 Name: Matthew Lorette Anaya
 */
 /***********************************************
Author: Matthew Lorette Anaya
Date: 11/06/2019
Purpose: making stub function calls from stub functions
Sources of Help: Zybooks
Time Spent: 30mins
***********************************************/
 #include <stdio.h>

int convert_lengths(void);
int convert_weights(void);
void length_to_metric(void);
void length_to_us(void);
void weight_to_metric(void);
void weight_to_us(void);

int main(int argc, char *argv[]){
   int choice;
   
   do{
      printf("1. convert lenghts\n");
      printf("2. convert weights\n");
      printf("0. Exit\n");
      printf("Please choose from (1, 2, 0):\n");
      scanf("%d", &choice);
   
      switch (choice){
      
         case 1:
            choice = convert_lengths();
            break;
         
         case 2:
            choice = convert_weights();
            break;
         
         case 0:
            printf("User chose to exit.\n");
            break;
      }
   }while (choice != 0);
   
   return 0;
}

// Stub function for converting lengths.
int convert_lengths(void){
   int lChoice;

   printf("The user wants to convert_lengths.\n");
   
   do{
      printf("1. convert lengths to metric\n");
      printf("2. convert lengths to us\n");
      printf("0. Return to Main Menu\n");
      scanf("%d", &lChoice);
      
      switch (lChoice){
      
         case 1:
            length_to_metric();
            break;
         
         case 2:
            length_to_us();
            break;
         
         case 0:
            printf("User chose to go main menu.\n");
            break;
      }
   }while (lChoice != 0);
   
   return 0;
   
}
// Stub functon for converting weights.
int convert_weights(void){
   int wChoice;
   
   printf("The user wants to convert_weights.\n");
   
   do{
      printf("1. convert weights from pounds/ounces to kilograms/grams\n");
      printf("2. convert weights fomr kilograms/grams to pounds/ounces\n");
      printf("0. Return to Main Menu\n");
      scanf("%d", &wChoice);
      
      switch (wChoice){
      
         case 1:
            weight_to_metric();
            break;
         
         case 2:
            weight_to_us();
            break;
         
         case 0:
            printf("User chose to go main menu.\n");
            break;
      }
   }while (wChoice != 0);
   
   return 0;
}
// Stub feet/inches to meters/centimeters.
void length_to_metric(void){
   printf("The user wants to convert length_to_metric.\n\n");
}
// Stub meters/centimeters to feet/inches.
void length_to_us(void){
   printf("The user wants to convert length_to_us.\n\n");
}
// Stub pounds/ounces to kilograms/grams.
void weight_to_metric(void){
   printf("The user wants to convert weight_to_metric.\n\n");
}
// Stub kilograms/grams to pounds/ounces.
void weight_to_us(void){
   printf("The user wants to convert weight_to_us.\n\n");
}
