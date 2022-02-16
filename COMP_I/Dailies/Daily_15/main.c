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
 
 Date: 10/17/2019
 Name: Matthew Lorette Anaya
 */
 /***********************************************
Author: Matthew Lorette Anaya
Date: 10/17/2019
Purpose: using functions and enumerated values to play a game of
         rock paper scissors maling the main function easier to
         read.
Sources of Help: Zybooks
Difference: using functions cleans up the main function making it easier
            to read and edit if any changes were needed to be made.
Time Spent: 20mins
***********************************************/
 
 #include <stdio.h>

 enum Choice {ROCK, PAPER, SCISSORS};
 
 int get_player_choice(char);
 void game_conclusion(int, int);
 void clear_keyboard_buffer(void);
 
 int main (int argc, char  *argv[]){
    int player1, player2;
    char input1, input2;
    
    printf("Player-1, please enter your choice <p>aper, <r>ock, or <s>cissors:\n");
    scanf(" %c", &input1);
    clear_keyboard_buffer();
    player1 = get_player_choice(input1);
    
    printf("Player-2, please enter your choice <p>aper, <r>ock, or <s>cissors:\n");
    scanf(" %c", &input2);
    clear_keyboard_buffer();
    player2 = get_player_choice(input2);
    
    game_conclusion(player1, player2);
    
    
    return 0;
 }
 int get_player_choice(char choice){
    
    if ((choice == 'P') || (choice == 'p')){
      choice = PAPER;
   }
   else if ((choice == 'R') || (choice == 'r')){
      choice = ROCK;
   }
   else if ((choice == 'S') || (choice == 's')){
      choice = SCISSORS;
   }
   else{
      printf("I do not understand. Please enter your choice <p>aper, <r>ock, or <s>cissors:\n");
      scanf(" %c", &choice);
      clear_keyboard_buffer();
      choice = get_player_choice(choice);
   }
   return choice;
}
void game_conclusion(int player1, int player2){
   
    switch (player1){
      case PAPER:
      
         switch(player2){
            case PAPER:
               printf("Draw, nobody wins.\n");
               break;
          
            case ROCK:
               printf("Player-1 wins! Paper covers rock!\n");
               break;
          
            case SCISSORS:
               printf("Player-2 wins! Scissors cut paper!\n");
               break;
         }
      break;
      
      case ROCK:
         
         switch(player2){
            case PAPER:
               printf("Player-2 wins! Paper covers rock!\n");
               break;
            
            case ROCK:
               printf("Draw, nobody wins.\n");
               break;
            
            case SCISSORS:
               printf("Player-1 wins! Rock breaks scissors!\n");
               break;
         }
      break;
      
      case SCISSORS:
         switch(player2){
            case PAPER:
               printf("Player-1 wins! Scissors cut paper!\n");
               break;
            
            case ROCK:
               printf("Player-2 wins! Rock breaks scissors!\n");
               break;
               
            case SCISSORS:
               printf("Draw, nobody wins.\n");
               break;
         }
      break;
   }
}
void clear_keyboard_buffer(void)
{
 char ch;
 scanf("%c", &ch);
 while (ch != '\n' && ch != '\0') {
 scanf("%c", &ch);
 }
}

