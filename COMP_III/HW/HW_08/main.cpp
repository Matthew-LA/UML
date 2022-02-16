/***********************************************
 Author: Matthewl Lorette Anaya
 Date:  11/08/2020
 Purpose: familiarizing with maps
 Sources of Help: recorded lectures
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
 Date: 11/08/2020
 Name: Matthew Lorette Anaya
*/

#include <iostream>
#include <string>

using namespace std;

class Person{
public:
    Person();
    Person(string theName);
    Person(const Person& theObject);
    
    string getName() const;
    Person& operator=(const Person& rtSide);
    friend istream& operator >>(istream& inStream, Person& pObject);
    friend ostream& operator <<(ostream& outStream, const Person& pObject);
    
private:
       string name;
};

class Vehicle{
public:
    Vehicle();
    Vehicle(string m, int cyl, Person &own);
    Vehicle(const Vehicle &copy);
    
    string get_make()const;
    int get_cylinders()const;
    Person get_owner()const;
    Vehicle& operator=(const Vehicle& rtSide);
    friend ostream& operator <<(ostream& out, const Vehicle& vObj);
    
private:
    string make;
    int cylinders;
    Person owner;

};

class Truck: public Vehicle{
public:
    Truck();
    Truck(string m, int cyl, Person &own, double load, int tow);
    Truck(const Truck &copy);
    
    double get_load();
    int get_tow();
    Truck& operator=(const Truck& rtSide);
    friend ostream& operator <<(ostream& out, const Truck& tObj);
    
private:
    double load_tons;
    int tow_lbs;
};


int main(int argc, const char * argv[]) {
  
    cout << "/////////////// Testing Person Class ///////////////" << endl;
    Person p1;
    cout << "Testing default constructor: the person is: " << p1 << endl;
    Person p2("Matt LA");
    cout << "Testing constructor(string): I am: " << p1 << endl;
    cout << "Testing >> overloading: ";
    cin >> p1;
    cout << "\t\t   You're: " << p1 << endl;
    p2 = p1;
    cout << "Testing = overloading: Another you is: " << p2 << endl << endl << endl;
    
    
    cout << "/////////////// Testing Vehicle Class ///////////////" << endl;
    Vehicle v1;
    cout << "Testing default constructor: the Vehicle is: " << endl;
    cout << "\t\t" << v1 << endl;
    Vehicle v2("Ford Van", 8, p1);
    cout << "Testing constructor(args): for my car:" << endl;
    cout << "\t\t" << v2 <<endl;
    Vehicle v3(v2);
    cout << "Testing copy constructor: my second same car:" << endl;
    cout << "\t\t" << v3 << endl;
    Person p3("James Smith");
    Vehicle v4("Ford", 6, p2);
    v1 = v4;
    cout << "Testing = overloading:" << endl;
    cout << "\t\tYour Car is: " << v4 << endl;
    cout << "\t\tYour Your Second Car is: " << v1 << endl << endl << endl;
    
    
    cout << "/////////////// Testing Truck Class ///////////////" << endl;
    Truck t1;
    cout << "Testing default constructor: the Truck is: \n\t\t  "  << t1 << endl;
    Person p4("Mike Elf");
    Truck t2("Mac", 8, p3, 250, 2000);
    cout << "Testing constructor(args): for a truck:\n\t\t  " << t2 << endl;
    Truck t3(t2);
    cout << "Testing copy constructor: copied truck:\n\t\t  " << t3 << endl;
    Truck hisTruck("Toyota Truck", 8, p2, 200, 5000);
    t1 = hisTruck;
    cout << "Testing = overloading:\n\t\t  hisTruck is: " << hisTruck << endl;
    cout << "\t\t  his same Truck is: " << t1 << endl;


    
    return 0;
}

Person::Person(): name("none"){
    //default constructor
};
Person::Person(string theName): name(theName){
    //argument constructor
};
Person::Person(const Person& theObject): name(theObject.name){
    //copy constructor
}
string Person::getName()const{return name;} //name variable accessor function
Person& Person::operator=(const Person& rtSide){ //copy assignment operator
    if(this == &rtSide){
        return *this;
    }
    this->name = rtSide.name;
    return *this;
    
}
//overloaded extraction operator
//first = Person object's first name
//last = Person object's last name
//full = first and last string concatenated to be
//       placed into the Person object's name variable
istream& operator >>(istream& inStream, Person& personObject){
    string first,
           last,
           full;
    
    cout << "Enter your name: ";
    inStream >> first;
    inStream >> last;
    full = first + " " + last;
    personObject.name = full;
    
    return inStream;
}
ostream& operator <<(ostream& outStream, const Person& pObject){ //overloaded insertion operator
    outStream << pObject.name;
    return outStream;
}


Vehicle::Vehicle(): make("Unknown Manufacturer"), cylinders(0), owner(Person("Unknown Owner")){
    //default constructor
};
Vehicle::Vehicle(string m, int cyl, Person &own): make(m), cylinders(cyl), owner(own.getName()){
    //args constructor
};
Vehicle::Vehicle(const Vehicle &copy): make(copy.make), cylinders(copy.cylinders), owner(copy.owner){
    //copy constructor
};
string Vehicle::get_make()const{return make;} //make variable accessor function
int Vehicle::get_cylinders()const{return cylinders;} //cylinders variable accessor function
Person Vehicle::get_owner()const{return owner;} //Person object/owner variable accessor function
Vehicle& Vehicle::operator=(const Vehicle &rtSide){ //overloaded copy assignmnet operator
    if(this == &rtSide){
        return *this;
    }
    this->make = rtSide.make;
    this->cylinders = rtSide.cylinders;
    this->owner = rtSide.owner;
    
    return *this;
}
ostream& operator <<(ostream& out, const Vehicle& vObj){ //overloaded insertion operator
    out << vObj.make << ", " << vObj.cylinders << " cylinders, " << "belongs to: " << vObj.owner;
    
    return out;
}

Truck::Truck(): load_tons(0), tow_lbs(0), Vehicle(){
    //default constructor
}
Truck::Truck(string m, int cyl, Person &own, double load, int tow)
    :load_tons(load), tow_lbs(tow), Vehicle(m, cyl, own){
    //args constructor
}
Truck::Truck(const Truck &copy): load_tons(copy.load_tons), tow_lbs(copy.tow_lbs), Vehicle(copy){
    //copy constructor
}
double Truck::get_load(){return load_tons;} //load_tons variable accessor function
int Truck::get_tow(){return tow_lbs;} //tow_lbs variable accessor function
Truck& Truck::operator=(const Truck& rtSide){ //overloaded copy assignmnet operator
    if(this == &rtSide){
        return *this;
    }
    this->load_tons = rtSide.load_tons;
    this->tow_lbs = rtSide.tow_lbs;
    this->Vehicle::operator=(rtSide);
    
    return *this;
}
ostream& operator <<(ostream& out, const Truck& tObj){ //overloaded insertion operator
    out << tObj.get_make() << ", " << tObj.get_cylinders() << " cylinders, " << "belongs to: " << tObj.get_owner() << ", load capacity: " << tObj.load_tons << ", towing capacity: " << tObj.tow_lbs;
    
    return out;
}











