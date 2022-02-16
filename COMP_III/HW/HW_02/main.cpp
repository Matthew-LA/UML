 /***********************************************
 Author:Matthew Lorette Anaya
 Date: 09/20/2020
 Purpose: Reads from a file and changes "dislike" to "love"
 Sources of Help: link in assignment
 Time Spent: 20 mins
  
Computing III -- COMP.2010 Honor Statement
The practice of good ethical behavior is essential for maintaining good order in the classroom, providing an enriching learning experience for students, and as training as a practicing computing professional upon graduation. This practice is manifested in the University’s Academic Integrity policy. Students are expected to strictly avoid academic dishonesty and adhere to the Academic Integrity policy as outlined in the course catalog. Violations will
be dealt with as outlined therein.
I certify that the work submitted with this assignment is mine and was generated in a manner consistent with this document, the course academic policy on the course website on Blackboard, and the UMass Lowell academic code.
  Date: 09/20/2020
  Name: Matthew Lorette Anaya
 ***********************************************/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(int argc, const char * argv[])
{
    //variable assignment for what file needs to read.
    string file = "/Users/matthewloretteanaya/Documents/COMPIII/input.txt";
    string word;
    ifstream inStream;
    
    //open file for input, if fail exit.
    inStream.open(file);
    if(inStream.fail()){
        cout << "Cant open input file" << endl;
        exit(1);
    }
    //read file into string and change keywords
    while(inStream >> word){
        if (word == "dislike"){
            word = "love";
        }
        cout << word << " ";
    }
    //close file
    inStream.close();
    
    return 0;
}
