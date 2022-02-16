 /***********************************************
 Author: Matthew Lorette Anaya
 Date: 10/03/2020
 Purpose: <Insert a short description of what
 your program does here.>
 Sources of Help: internet
 Time Spent: 6 hours
 ***********************************************/
/*
Computing III -- COMP.2010 Honor Statement
The practice of good ethical behavior is essential for maintaining good order in the classroom, providing an enriching learning experience for students, and as training as a practicing computing professional upon graduation. This practice is manifested in the University’s Academic Integrity policy. Students are expected to strictly avoid academic dishonesty and adhere to the Academic Integrity policy as outlined in the course catalog. Violations will
be dealt with as outlined therein.
 All programming assignments in this class are to be done by the student alone. No outside help is permitted except the instructor and
 approved tutors.
I certify that the work submitted with this assignment is mine and was generated in a manner consistent with this document, the course academic policy on the course website on Blackboard, and the UMass
Lowell academic code.
 Date: 10/03/2020
 Name: Matthew Lorette Anaya
*/
#include <iostream>
#include <string>

using namespace std;

class Rational{
public:
    Rational(){
        numerator = 0;
        denominator = 1;
    }
    Rational(int wholeNumber){
        numerator = wholeNumber;
        denominator = 1;
    }
    Rational(int top, int bottom){
        numerator = top;
        denominator = bottom;
        gcd(numerator, denominator);
        normalize(numerator, denominator);
    }
    int getNumerator()const{
        return numerator;
    }
    int getDenominator()const{
        return denominator;
    }
    
private:
    int numerator,
        denominator;
    
    void gcd(int &numerator, int &denominator);
    void normalize(int &numerator, int &denominator);
    
};

bool operator ==(const Rational &a, const Rational &b);
bool operator <(const Rational &a, const Rational &b);
bool operator <=(const Rational &a, const Rational &b);
bool operator >(const Rational &a, const Rational &b);
bool operator >=(const Rational &a, const Rational &b);

const Rational operator +(const Rational &a, const Rational &b);
const Rational operator -(const Rational &a, const Rational &b);
const Rational operator *(const Rational &a, const Rational &b);
const Rational operator /(const Rational &a, const Rational &b);

ostream & operator <<(ostream  &out, const Rational &r);
istream & operator >>(istream  &in, Rational &r);

int gcd(int a, int b);
int lcm(int a, int b);


int main(int argc, const char * argv[])
{
    Rational r1, r2, r3, r4, r5;
    int choice, //variable to choose which manipulation function
        count = 0; //variable to keep track of a play through
    char play, //variable to continue playing
         change; //variable used to change fractions or not
    bool outcome; //variable used for boolean manipulation functions
    
    r4 = Rational();
    cout << "The default Rational constructor = " << r4 << endl;
    r5 = Rational(8);
    cout << "The Whole Number constructor with an 8 as an argument = " << r5 << endl;
    
    do{
        //first playthrought
        if(count == 0){
            cout << "Enter the fractions you would like to manipulate." << endl
                 << "Enter 1st fraction." << endl;
            cin >> r1;
            cout << "Now enter the 2nd fraction." << endl;
            cin >> r2;
        }
        //after first play through to ask if user wants to change fractions
        else{
            cout << "If you would like to change the previous fractions press Y/y. If not press any other character to keep them."
                 << endl;
            cin >> change;
            if(change == 'Y' || change == 'y'){
                cout << "Enter a fractions you would like to manipulate." << endl
                     << "Enter first fraction." << endl;
                cin >> r1;
                cout << "Now enter the second fraction." << endl;
                cin >> r2;
            }
        }
        //Choosing how the user wants to manipulate the fractions
        cout << "Now enter the associated character to manipulate the 1st fractions by the 2nd fraction." << endl
             << "Enter:\n" << "1(=)\n" << "2(<)\n" << "3(<=)\n" << "4(>)\n" << "5(>=)\n" << "6(+)\n" << "7(-)\n"
             << "8(*)\n" << "9(/)" << endl;
        cin >> choice;
        
        switch(choice){
            case 1: //eaqual to
                outcome = r1 == r2;
                if (outcome == true){
                    cout << r1 << " is equal to " << r2 << endl;
                }
                else{
                    cout << r1 << " is not equal to " << r2 << endl;
                }
                break;
            case 2: //less than
                outcome = r1 < r2;
                if (outcome == true){
                    cout << r1 << " is less than " << r2 << endl;
                }
                else{
                    cout << r1 << " is not less than " << r2 << endl;
                }
                break;
            case 3: //less than or equal to
                outcome = r1 <= r2;
                if (outcome == true){
                    cout << r1 << " is less than or equal to " << r2 << endl;
                }
                else{
                    cout << r1 << " is not less than or equal to " << r2 << endl;
                }
                break;
            case 4: //greater than
                outcome = r1 > r2;
                if (outcome == true){
                    cout << r1 << " is greater than " << r2 << endl;
                }
                else{
                    cout << r1 << " is not greater than " << r2 << endl;
                }
                break;
            case 5: //greater than or equal to
                outcome = r1 >= r2;
                if (outcome == true){
                    cout << r1 << " is greater than or equal to " << r2 << endl;
                }
                else{
                    cout << r1 << " is not greater than or equal to " << r2 << endl;
                }
                break;
            case 6: //addition
                r3 = r1 + r2;
                cout << r1 << " + " << r2 << " = " << r3 << endl;
                break;
            case 7: //subtraction
                r3 = r1 - r2;
                cout << r1 << " - " << r2 << " = " << r3 << endl;
                break;
            case 8: //multiplication
                r3 = r1 * r2;
                cout << r1 << " * " << r2 << " = " << r3 << endl;
                break;
            case 9: //division
                r3 = r1 / r2;
                cout << r1 << " / " << r2 << " = " << r3 << endl;
                break;
        }
        //user chooses to play again or quite
        cout << "Enter Y/y to continue or any other character to quite." << endl;
        cin >> play;
        count++;
    }while(play == 'Y' || play == 'y');
          
    return 0;
}
//class function greatest common denominator
void Rational::gcd(int &numerator, int &denominator){
    int  temp,
         tNum = numerator,
         tDen = denominator;
    
    while(tNum != 0){
        temp = tDen % tNum;
        tDen = tNum;
        tNum = temp;
    }
    numerator /= tDen;
    denominator /= tDen;
}
//function if denominator is negative swap the sign with numerator.
//if both are negative make positive
void Rational::normalize(int &numerator, int &denominator){
    if(denominator < 0){
        numerator = -numerator;
        denominator = -denominator;
    }
}
//first class parameter equal to second class parameter
bool operator ==(const Rational &a, const Rational &b){
    return((a.getNumerator() * b.getDenominator()) == (b.getNumerator() * a.getDenominator()));
}
//first class parameter less than second class parameter
bool operator <(const Rational &a, const Rational &b){
    if(a.getNumerator() > 0 && b.getNumerator() < 0){
        return false;
    }
    if(a.getNumerator() < 0 && b.getNumerator() > 0){
        return true;
    }
    else{
        return((a.getNumerator() * b.getDenominator()) < (b.getNumerator() * a.getDenominator()));
    }
}
//first class parameter less than or equal to second class parameter
bool operator <=(const Rational &a, const Rational &b){
    if(a.getNumerator() > 0 && b.getNumerator() < 0){
        return false;
    }
    if(a.getNumerator() < 0 && b.getNumerator() > 0){
        return true;
    }
    else{
        return((a.getNumerator() * b.getDenominator()) < (b.getNumerator() * a.getDenominator())
               || (a.getNumerator() * b.getDenominator()) == (b.getNumerator() * a.getDenominator()));
    }
}
//first class parameter greater than second class parameter
bool operator >(const Rational &a, const Rational &b){
    if(a.getNumerator() < 0 && b.getNumerator() > 0){
        return false;
    }
    if(a.getNumerator() > 0 && b.getNumerator() < 0){
        return true;
    }
    else{
        return((a.getNumerator() * b.getDenominator()) > (b.getNumerator() * a.getDenominator()));
    }
}
//first class parameter greater than or equal to second class parameter
bool operator >=(const Rational &a, const Rational &b){
    if(a.getNumerator() < 0 && b.getNumerator() > 0){
        return false;
    }
    if(a.getNumerator() > 0 && b.getNumerator() < 0){
        return true;
    }
    else{
        return((a.getNumerator() * b.getDenominator()) > (b.getNumerator() * a.getDenominator())
               || (a.getNumerator() * b.getDenominator()) == (b.getNumerator() * a.getDenominator()));
    }
}
//cout overload function to display Rational fraction as "xx/yy" format
ostream & operator <<(ostream  &out, const Rational &r){
    out << r.getNumerator() << "/" << r.getDenominator();
    
    return out;
}
//cin overload function to read in class Rational fraction as "xx/yy" format
istream & operator >>(istream  &in, Rational &r){
    int top,
        bottom;
    char slash;
    
    cout << "Enter a fraction in a \"xx/yy\" format: ";
    in >> top;
    in >> slash;
    in >> bottom;
    while(bottom == 0){
        cout << "Invalid input. The denominator cannot be zero." << endl <<"Enter a valid fraction(\"xx/yy\" format): ";
        in >> top;
        in >> slash;
        in >> bottom;
    }
    
    r = Rational(top, bottom);
    
    return in;
}
//global greatest common denominator function called by lcm function
int gcd(int a, int b){
    if (a == 0){
        return b;
    }
    return gcd(b % a, a);
}
//global lowest common multiple function used to simplify fractions
//makes call to global gcd function to do so
int lcm(int a, int b){
    return (a * b) / gcd(a, b);
}
//addition overload function
//adds the first and second class parameters together
const Rational operator +(const Rational &a, const Rational &b){
    int sum,
        lcd;
    
    lcd = lcm(a.getDenominator(), b.getDenominator());
    sum = ((lcd / a.getDenominator()) * a.getNumerator()) + ((lcd / b.getDenominator()) * b.getNumerator());
    
    return Rational(sum, lcd);
}
//subtraction overload function
//subtracts the second class parameter from the first
const Rational operator -(const Rational &a, const Rational &b){
    int sum,
        lcd;
    
    lcd = lcm(a.getDenominator(), b.getDenominator());
    sum = ((lcd / a.getDenominator()) * a.getNumerator()) - ((lcd / b.getDenominator()) * b.getNumerator());
    
    return Rational(sum, lcd);
}
//multiplication overload function
//multiplies the first class parameter by the second
const Rational operator *(const Rational &a, const Rational &b){
    return Rational((a.getNumerator()* b.getNumerator()), (a.getDenominator()*b.getDenominator()));
}
//division overload function
//divided the first class paramter by the second
const Rational operator /(const Rational &a, const Rational &b){
    return Rational((a.getNumerator() * b.getDenominator()), (a.getDenominator()*b.getNumerator()));
}

