/***********************************************
 Author: Matthew Lorette Anaya
 Date: 12/01/2020
 Purpose: familiarizing with algorithm functions
 Sources of Help: cpp reference
 Time Spent: 20 mins
 ***********************************************/
/*
Computing III -- COMP.2010 Honor Statement
The practice of good ethical behavior is essential for maintaining good order in the classroom, providing an enriching learning experience for students, and as training as a practicing computing professional upon graduation. This practice is manifested in the University’s Academic Integrity policy. Students are expected to strictly avoid academic dishonesty and adhere to the Academic Integrity policy as outlined in the course catalog. Violations will
be dealt with as outlined therein.
 All programming assignments in this class are to be done by the student alone. No outside help is permitted except the instructor and
 approved tutors.
I certify that the work submitted with this assignment is mine and was generated in a manner consistent with this document, the course academic policy on the course website on Blackboard, and the UMass
Lowell academic code.
 Date: 12/01/2020
 Name: Matthew Lorette Anaya
*/
#include <iostream>
#include <list>
#include <string>
#include <sstream>
#include <algorithm>
#include <iterator>


using namespace std;

list<string> generate_permutations(list<string> inputList);
void print_permutations(const list<string> permutations);

int main(int argc, char *argv[]){
    
    list<string> inputList;
    string aLine, aString;
    
    // read in strings from stdin
    cout << "Enter strings, separated by a space:";
    getline(cin, aLine); //read a line from keyboard
    istringstream iss(aLine); //convert aLine to an istringstream obj
    
    //parse each string
    while(iss >> aString) {
        inputList.push_back(aString);
        
    }
    auto permutations = generate_permutations(inputList);
    // print permutations to stdout
    print_permutations(permutations);
    
    return 0;
}

list<string> generate_permutations(list<string> inputList){
    //empty list to hold permutations
    list<string> permList;
    string temp;
    
    //sorting the inputList
    inputList.sort();
    //retrieves the unique string of permutaions
    inputList.unique();
    
    list<string>::iterator i;
    
    //do while loop to find all permutations
    //and fill the permList with them
    do{
        temp = "";
        for(i = inputList.begin(); i != inputList.end(); i++){
            temp += i->c_str();
            temp += " ";
        }
        permList.push_back(temp);
    }while(next_permutation(inputList.begin(), inputList.end()));
    
    return permList;
}

void print_permutations(const list<string> permutations){
    int count = 1;
    
    for(auto &p : permutations){
        cout << count << ". " << p << endl;
        count++;
    }
}
