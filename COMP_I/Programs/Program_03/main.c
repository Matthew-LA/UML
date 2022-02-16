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
 
 Date: 11/17/2019
 Name: Matthew Lorette Anaya
 */
 /***********************************************
Author: Matthew Lorette Anaya
Date: 11/17/2019
Purpose: practicing top down design and finishing stub functions.
Sources of Help: Zybooks
Time Spent: 3 hours
***********************************************/
 #include <stdio.h>

int convert_lengths(void);
int convert_weights(void);

void length_to_metric(void);
void length_to_us(void);
void weight_to_metric(void);
void weight_to_us(void);

void read_length_us(int* feet, double* inches);
void convert_length_to_metric(int feet, double inches, int* meters, double* centimeters);
void output_length_metric(int feet, double inches, int meters, double centimeters);

void read_length_metric(int* meters, double* centimeters);
void convert_length_to_us(int meters, double centimeters, int* feet, double* inches);
void output_length_us(int feet, double inches, int meters, double centimeters);

void read_weight_us(int* pounds, double* ounces);
void convert_weight_to_metric(int pounds, double ounces, int* kilograms, double* grams);
void output_weight_metric(int pounds, double ounces, int kilograms, double grams);

void read_weight_metric(int* kilograms, double* grams);
void convert_weight_to_us(int kilograms, double grams, int* pounds, double* ounces);
void output_weight_us(int pounds, double ounces, int kilograms, double grams);

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

// Function for converting lengths.
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
// Functon for converting weights.
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
// Feet/inches to meters/centimeters.
void length_to_metric(void){
   int feet, meters;
   double inches, centimeters;
   read_length_us(&feet, &inches);
   convert_length_to_metric(feet, inches, &meters, &centimeters);
   output_length_metric(feet, inches, meters, centimeters);
}
// Meters/centimeters to feet/inches.
void length_to_us(void){
   int feet, meters;
   double inches, centimeters;
   read_length_metric(&meters, &centimeters);
   convert_length_to_us(meters, centimeters, &feet, &inches);
   output_length_us(feet, inches, meters, centimeters);
}
// Pounds/ounces to kilograms/grams.
void weight_to_metric(void){
   int pounds, kilograms;
   double ounces, grams;
   read_weight_us(&pounds, &ounces);
   convert_weight_to_metric(pounds, ounces, &kilograms, &grams);
   output_weight_metric(pounds, ounces, kilograms, grams);
}
// Kilograms/grams to pounds/ounces.
void weight_to_us(void){
   int pounds, kilograms;
   double ounces, grams;
   read_weight_metric(&kilograms, &grams);
   convert_weight_to_us(kilograms, grams, &pounds, &ounces);
   output_weight_us(pounds, ounces, kilograms, grams);
}
// Get input for feet/inches.
void read_length_us(int* feet, double* inches){
   int x;
   double yy;
   printf("Enter feet and inches (seperated by a space):\n");
   scanf("%d %lf", &x, &yy);
   *feet = x;
   *inches = yy;
}
// Convert feet/inches to meters/centimeters.
void convert_length_to_metric(int feet, double inches, int* meters, double* centimeters){
   int tempMeters;
   
   *meters = 0.3048 * feet;
   tempMeters = *meters;
   *centimeters = ((((inches /12.0) * 0.3048) * 100) + ((((double)feet * 0.3048 - tempMeters) * 100)));
   while (*centimeters >= 100){
      *centimeters -= 100;
      *meters += 1;
   }
}
// Print the metric conversion.
void output_length_metric(int feet, double inches, int meters, double centimeters){
   printf("%d feet and %.4f inches converted to %d meters and %.4f centimeters.\n", feet, inches, meters, centimeters);
}
// Get input for meters/centimeters.
void read_length_metric(int* meters, double* centimeters){
   int x;
   double yy;
   printf("Enter meters and centimeters (seperated by a space):\n");
   scanf("%d %lf", &x, &yy);
   *meters = x;
   *centimeters = yy;
}
// Convert meters/centimeters to feet/inches.
void convert_length_to_us(int meters, double centimeters, int* feet, double* inches){
  int tempFeet;
  
   *feet = meters / 0.3048;
   tempFeet = *feet;
   *inches = ((((centimeters / 100) / 0.3048) * 12) + (((double)meters / 0.3048 - tempFeet) * 12));
   while(*inches >= 12){
      *inches -= 12;
      *feet += 1;
   }
}
// Print the us conversion.
void output_length_us(int feet, double inches, int meters, double centimeters){
   printf("%d meters and %.4f centimeters converted to %d feet and %.4f inches.\n", meters, centimeters, feet, inches);
}
// Get input for pounds/ounces.
void read_weight_us(int* pounds, double* ounces){
   int x;
   double yy;
   
   printf("Enter pounds and ounces (seperated by a space):\n");
   scanf("%d %lf", &x, &yy);
   *pounds = x;
   *ounces = yy;
}
// Convert pounds/ounces to kilograms/grams.
void convert_weight_to_metric(int pounds, double ounces, int* kilograms, double* grams){
   int tempKilograms;
   
   *kilograms = pounds / 2.2056;
   tempKilograms = *kilograms;
   *grams = ((((ounces / 16) / 2.2046) *1000) + (((double)pounds / 2.2046 - tempKilograms) * 1000));
   while (*grams >= 1000){
      *grams -= 1000;
      *kilograms += 1;
   }
}
// Print metric conversion.
void output_weight_metric(int pounds, double ounces, int kilograms, double grams){
   printf("%d pounds and %.4f ounces converted to %d kilograms and %.4f grams.\n", pounds, ounces, kilograms, grams);
}
// Get input for kilograms/grams.
void read_weight_metric(int* kilograms, double* grams){
   int x;
   double yy;
   
   printf("Enter kilograms and grams (seperated by a space):\n");
   scanf("%d %lf", &x, &yy);
   *kilograms = x;
   *grams = yy;
}
// Convert kilograms/grams to pounds/ounces.
void convert_weight_to_us(int kilograms, double grams, int* pounds, double* ounces){
   int tempPounds;
   
   *pounds = kilograms * 2.2046;
   tempPounds = *pounds;
   *ounces = ((((grams / 1000) * 2.2046) * 16) + (((double)kilograms * 2.2046 - tempPounds) *16));
   while (*ounces >= 16){
      *ounces -= 16;
      *pounds += 1;
   }
}
// Print us conversion.
void output_weight_us(int pounds, double ounces, int kilograms, double grams){
   printf("%d kilograms and %.4f grams converted to %d pounds and %.4f ounces.\n", kilograms, grams, pounds, ounces);
}
