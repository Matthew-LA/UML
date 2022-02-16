/***********************************************
 Author: Matthewl Lorette Anaya
 Date:  11/03/2020
 Purpose: familiarizing with maps
 Sources of Help: lives lectures
 Time Spent: 1 hour
 ***********************************************/
/*
Computing III -- COMP.2010 Honor Statement
The practice of good ethical behavior is essential for maintaining good order in the classroom, providing an enriching learning experience for students, and as training as a practicing computing professional upon graduation. This practice is manifested in the University’s Academic Integrity policy. Students are expected to strictly avoid academic dishonesty and adhere to the Academic Integrity policy as outlined in the course catalog. Violations will
be dealt with as outlined therein.
 All programming assignments in this class are to be done by the student alone. No outside help is permitted except the instructor and
 approved tutors.
I certify that the work submitted with this assignment is mine and was generated in a manner consistent with this document, the course academic policy on the course website on Blackboard, and the UMass
Lowell academic code.
 Date: 11/03/2020
 Name: Matthew Lorette Anaya
*/
#include<iostream>
#include<fstream>
#include<string>
#include<cmath>
#include<map>

using namespace std;

int main(){
    ifstream in;
    
    map<string,int[2]> ratings;
    string movie,
           movieName;
    int rating,
        reviewCount = 0,
        reviewSum = 0,
        i = 0,
        j = 0;
    double average = 1;
   
    int numOfRev;
    ///Users/matthewloretteanaya/Downloads/HW07.txt
    in.open("movies.txt");
                                    
    if(in.fail()){
        cout<<"Input file opening failed.\n";
        exit(1);
    }
    
    in >> numOfRev;
    in.ignore();
    string order[numOfRev];
    
    while(getline(in,movie)){
        in >> rating;
        in.ignore();
        if(ratings.find(movie) == ratings.end()){
            order[i] = movie;
            i++;
        }
        ratings[movie][0]++;
        ratings[movie][1] += rating;
    }
    in.close();
    
    for(j = 0; j < i; j++){
        movieName = order[j];
        reviewCount = ratings[movieName][0];
        reviewSum = ratings[movieName][1];
        average = (double)reviewSum/(double)reviewCount;
        average = floor(average*10)/10;
        cout << movieName << ":  " << reviewCount << " reviews, average of " << average << " / 5" << endl;
    }
    return 0;

}
