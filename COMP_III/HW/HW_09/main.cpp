/***********************************************
 Author: Matthew Lorette Anaya
 Date: 11/14/2020
 Purpose: familiarizing with virtual functions
 Sources of Help: internet
 Time Spent: 2 hours
 ***********************************************/
/*
Computing III -- COMP.2010 Honor Statement
The practice of good ethical behavior is essential for maintaining good order in the classroom, providing an enriching learning experience for students, and as training as a practicing computing professional upon graduation. This practice is manifested in the University’s Academic Integrity policy. Students are expected to strictly avoid academic dishonesty and adhere to the Academic Integrity policy as outlined in the course catalog. Violations will
be dealt with as outlined therein.
 All programming assignments in this class are to be done by the student alone. No outside help is permitted except the instructor and
 approved tutors.
I certify that the work submitted with this assignment is mine and was generated in a manner consistent with this document, the course academic policy on the course website on Blackboard, and the UMass
Lowell academic code.
 Date: 11/14/2020
 Name: Matthew Lorette Anaya
*/
#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

class Player{
public:
    virtual int getGuess(){
        return 0;
    }
    virtual int getGuess(int compGuess, int playerGuess, int answer){
        return 0;
    }
};

class HumanPlayer: public Player{
public:
    int getGuess(){
        int guess;
        
        cout << "Enter your guess: ";
        cin >> guess;
        
        return guess;
    }
    int getGuess(int compGuess, int playerGuess, int answer){
        int guess;
        
        cout << "Enter your guess: ";
        cin >> guess;
        
        return guess;
    }
};

class ComputerPlayer: public Player{
public:
    int getGuess(){
        int guess;
        guess = rand() % 100;
        cout << "The computer guesses " << guess << endl;
        
        return guess;
    }
    int getGuess(int compGuess, int playerGuess, int answer){
        int guess = 0;

        
        if(compGuess < answer && playerGuess < answer ){
           if(playerGuess <= compGuess){
               guess = rand() % (100 - compGuess +1) + compGuess;
           }
           else{
               guess = rand() % (100 - playerGuess +1) + playerGuess;
           }
        }
        if(compGuess < answer && playerGuess > answer){
            guess = rand() % (playerGuess - compGuess +1) + compGuess;
        }
        if(compGuess > answer && playerGuess < answer){
            guess = rand() % (compGuess - playerGuess +1) + playerGuess;
        }
        if(compGuess > answer && playerGuess > answer){
            if(compGuess <= playerGuess){
                guess = rand() % compGuess;
            }
            else{
                guess = rand() % playerGuess;
            }
        }
        cout << "The computer guesses " << guess << endl;
        return guess;
    }
};

void play(Player &player1, Player &player2);
bool checkForWin(int guess, int answer);

int main(int argc, const char * argv[]) {
    ComputerPlayer c1, c2;
    HumanPlayer p1, p2;
    int choice;
    
    srand(time(nullptr));
    
    do{
        cout << "Enter a choice:\n(1)Player vs Player\n(2)Player vs Computer\n(3)Computer vs Computer\nPress any other number to quite.\n";
        cin >> choice;
        switch(choice){
            case 1:
                cout << "******Player vs Player******" << endl
                     << "----------------------------" << endl;
                play(p1,p2);
                break;
                
            case 2:
                cout << "******Player vs Computer******" << endl
                     << "------------------------------" << endl;
                play(p1,c1);
                break;
                
            case 3:
                cout << "******Computer vs Computer******" << endl
                     << "--------------------------------" << endl;
                play(c1,c2);
                break;
                
            default:
                break;
        }
    }while(choice == 1 || choice == 2 || choice == 3);
    
    

    return 0;
}

bool checkForWin(int guess, int answer) {
       if (answer == guess)
       {
           cout << "You're right! You win!" << endl;
           return true;
       }
       else if (answer < guess)
           cout << "Your guess is too high." << endl;
       else
           cout << "Your guess is too low." << endl; return false;
}
// The play function takes as input two Player objects.
void play(Player &player1, Player &player2){
    int answer = 0,
        p1Guess = 0,
        p2Guess = 0,
        numOfGuess = 0;
    
    
    answer = rand() % 100;
    bool win = false;
    
    while (!win)
    {
        if(numOfGuess < 1){
            cout << "Player 1's turn to guess." << endl; p1Guess = player1.getGuess();
            win = checkForWin(p1Guess, answer);
            if (win) return;
            cout << "Player 2's turn to guess." << endl; p2Guess = player2.getGuess();
            win = checkForWin(p2Guess, answer);
            numOfGuess++;
        }
        else{
            cout << "Player 1's turn to guess." << endl; p1Guess = player1.getGuess(p1Guess, p2Guess, answer);
            win = checkForWin(p1Guess, answer);
            if (win) return;
            cout << "Player 2's turn to guess." << endl; p2Guess = player2.getGuess(p2Guess, p1Guess, answer);
            win = checkForWin(p2Guess, answer);
            numOfGuess++;
        }
    }
}
