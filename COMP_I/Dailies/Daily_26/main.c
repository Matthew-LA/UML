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
 
 Date: 12/06/2019
 Name: Matthew Lorette Anaya
 */
 /***********************************************
Author: Matthew Lorette Anaya
Date: 12/06/2019
Purpose: using struct data types in functions
Sources of Help: Zybooks
Time Spent: 40 mins
***********************************************/
#include <stdio.h>

const int daysInMonth[12] = {31, 28, 31,
                             30, 31, 30,
                             31, 31, 30,
                             31, 30, 31};
typedef struct Month_Day_Year{
   int   month;
   int   day;
   int   year;
   }Date;

Date getYesterdayDate(Date);

int main(int argc, char* argv[]){
   Date  newDate;
   Date  oldDate;
   int   year = 2019;
   
   printf("Please enter a month (1-12):\n");
   scanf("%d", &oldDate.month);
   printf("Please enter a valid day in the month:\n");
   scanf("%d", &oldDate.day);
   oldDate.year = year;
   
   newDate = getYesterdayDate(oldDate);
   
   printf("Today is: %d/%d/%d\n", oldDate.month, oldDate.day, oldDate.year);
   printf("Yesterday is: %d/%d/%d\n", newDate.month, newDate.day, newDate.year);
   
   return 0;
}
Date getYesterdayDate(Date prevDate){
   Date date;
   //if if its the first day of the month.
   if(prevDate.day == 1){
      //if its january revert to december.
      if(prevDate.month == 1){
         date.month = 12;
         date.day = daysInMonth[11];
         date.year = prevDate.year - 1;
         return date;
      }
      //else revert to the previous month's last day.
      else{
            date.month = prevDate.month - 1;
            date.day = daysInMonth[prevDate.month - 2];
            date.year = prevDate.year;
            return date;
      }
   }
   //otherwise keep the month and revert to the previous day.
   else{
      date.month = prevDate.month;
      date.day = prevDate.day - 1;
      date.year = prevDate.year;
      return date;
   }
}
   
