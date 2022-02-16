/*
Computing III -- COMP.2010 Honor Statement
The practice of good ethical behavior is essential for maintaining good order in the classroom, providing an enriching learning experience for students, and as training as a practicing computing professional upon graduation. This practice is manifested in the University’s Academic Integrity policy. Students are expected to strictly avoid academic dishonesty and adhere to the Academic Integrity policy as outlined in the course catalog. Violations will be dealt with as outlined therein. All programming assignments in this class are to be done by the student alone. No outside help is permitted except the instructor and approved tutors.
     
I certify that the work submitted with this assignment is mine and was generated in a manner consistent with this document, the course academic policy on the course website on Blackboard, and the UMass
Lowell academic code.

Date: 09/16/2020
Name: Matthew Lorette Anaya
*/
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

const int MIN = 0;
const int MAX = 1000;

void get_floor(int &floor);
void get_ceiling(int &ceiling);
void validate_floor_ceiling(int &floor, int &ceiling);
void get_num_of_guesses(int &numOfGueses);
void game_on(int floor, int ceiling, int numOfGuess, bool &play);
int main(int argc, const char * argv[])
{
    srand(time(NULL));
    int floor,
        ceiling,
        numOfGuesses;
    bool play = true;
    
    do{
        get_floor(floor);
        get_ceiling(ceiling);
        validate_floor_ceiling(floor, ceiling);
        get_num_of_guesses(numOfGuesses);
        game_on(floor, ceiling, numOfGuesses, play);
    }while(play);
}
//Get the minimum of the guessing bounds(floor).
void get_floor(int &floor)
{
    do{
        cout << "Enter the lower bound of the number you would like to guess(greater than 0)." << endl;
        cin >> floor;
    }while(floor <= MIN);
}
//Get the maximum of the guessing bounds(ceiling).
void get_ceiling(int &ceiling)
{
    do{
        cout << "Enter the upper bound of the number you would like to guess(less than 1000 and greater than the lower bound)." << endl;
        cin >> ceiling;
    }while(ceiling >= MAX);
}
//validating the min and max of the guessing bounds to be within the directed amounts.
//floor = the minimum of guessing bounds
//ceiling = the maximum of the guessing bounds.
void validate_floor_ceiling(int &floor, int &ceiling)
{
    do{
        if(floor >= ceiling){
            cout << "Your input was invalid." << endl;
            get_floor(floor);
            get_ceiling(ceiling);
        }
        else{
            return;
        }
    }while(floor >= ceiling);
}
//Get the number of guesses the player can make.
//numOfGuesses = the maximum number of guesses the player can input.
void get_num_of_guesses(int &numOfGuesses)
{
    do{
        cout << "Please enter the number of chances you would like to guess the number.(at least 1 and less than 10)" << endl;
        cin >> numOfGuesses;
    }while(numOfGuesses < 1 || numOfGuesses >= 10);
}
//Initiate the guessing game and aske if they would like to play again.
//floor = the minimum of the guessing bounds
//ceiling = the maximum of the guessing bounds
//numOfGuesses = the maximum number of tries the player gets
//play = if true continue to play. if false stop the game.
void game_on(int floor, int ceiling, int numOfGuesses, bool &play)
{
    int guess;
    int target = rand() % (ceiling - floor + 1) + floor;
    char playAgain;
    
    
    while(numOfGuesses > 0){
        cout << "Enter a guess:" << endl;
        cin >> guess;
        
        if(guess < target){
            cout << "Sorry, your guess was too low." << endl;
        }
        else if(guess > target){
            cout << "Sorry, your guess was too high." << endl;
        }
        else{
            cout << "Congratulations, you guessed the correct number!" << endl;
            break;
        }
        
        numOfGuesses--;
        if(numOfGuesses == 0){
            cout << "Sorry, but you have ran out of guesses. The correct number was " << target
                 << "." << endl;
        }
    }
    
    cout << "Would you like to play again? Enter Y/y for yes or N/n for no:" << endl;
    cin >> playAgain;
    if(playAgain == 'Y' || playAgain == 'y'){
        return;
    }
    else if(playAgain == 'N' || playAgain == 'n'){
        play = false;
    }
    
}
