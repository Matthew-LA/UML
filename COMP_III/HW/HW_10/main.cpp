/***********************************************
 Author: Matthew Lorette Anaya
 Date: 11/22/2020
 Purpose: familiarizing with the big 3
 Sources of Help: lectures
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
 Date: 11/22/2020
 Name: Matthew Lorette Anaya
*/
#include <iostream>
#include <string>

using namespace std;

void testPFArrayD(void);
void testException(void);

class OutOfRange{
public:
    OutOfRange(): indexVal(-1), errMess("N/A"){};
    OutOfRange(int i, const string& error): indexVal(i), errMess(error){};
    
    int index()const{ return indexVal; }
    string err()const{ return errMess; }
    
private:
    int indexVal;
    string errMess;
};

//Objects of this class are partially filled arrays of doubles.
class PFArrayD
{
public:
    PFArrayD( ): a(new double[50]), capacity(50), used(0){};
    //Initializes with a capacity of 50.
    
    PFArrayD(int capacityValue): a(new double[capacityValue]), capacity(capacityValue), used(0){};
    
    PFArrayD(const PFArrayD& pfaObject){
        int i;
        
        a = new double(pfaObject.capacity);
        capacity = pfaObject.capacity;
        used = pfaObject.used;
        for(i = 0; i < used; i++){
            a[i] = pfaObject.a[i];
        }
    }
    
    void addElement(double element){
    //Precondition: The array is not full.
    //Postcondition: The element has been added.
        if(this->capacity == this->used){
            throw OutOfRange(this->capacity, "The array's capacity was exceeded");
        }
        a[used] = element;
        used++;
    }
    bool full( ) const { return (capacity == used); }
    //Returns true if the array is full, false otherwise.
    
    int getCapacity( ) const { return capacity; }
    
    int getNumberUsed( ) const { return used; }
    
    void emptyArray( ){ used = 0; }
    //Empties the array.
    
    double& operator[](int index){
        if(index >= used){
            throw (OutOfRange(index, "Illegal index in PFArrayD"));
        }
        return a[index];
    }
    //Read and change access to elements 0 through numberUsed - 1.
    
    PFArrayD& operator =(const PFArrayD& rightSide){
        int i;
        
        if (capacity != rightSide.capacity){
            delete []a;
            a = new double(rightSide.capacity);
        }
        capacity = rightSide.capacity;
        used = rightSide.used;
        for(i = 0; i < used; i++){
            a[i] = rightSide.a[i];
        }
        
        return *this;
    }
    
    ~PFArrayD( ){
            delete []a;
    }
private:
    double *a; //for an array of doubles.
    int capacity; //for the size of the array.
    int used; //for the number of array positions currently in use.
    
};

int main(int argc, char *argv[])
{
     cout << "This program tests the class PFArrayD.\n";
     
     char ans;
     int choice;
     do
     {
         cout << "choose to test:\n(1)testPFArrayD()\n(2)testException()\nEnter choice: ";
         cin >> choice;
         switch(choice){
             case 1:
                 testPFArrayD();
                 break;
             case 2:
                 testException();
                 break;
             default:
                 break;
         }
         cout << "Test again? (y/n) ";
         cin >> ans;
     }while ((ans == 'y') || (ans == 'Y'));
     
    return 0;
}

void testPFArrayD( )
{
    int cap;
    cout << "Enter capacity of this super array: ";
    cin >> cap;
    PFArrayD temp(cap);
    
    cout << "Enter up to " << cap << " nonnegative numbers.\n";
    cout << "Place a negative number at the end.\n";
    
    double next;
    cin >> next;
    while ((next >= 0) && (!temp.full( )))
    {
        temp.addElement(next);
        cin >> next;
    }
    
    cout << "You entered the following "
    << temp.getNumberUsed( ) << " numbers:\n";
    int index;
    int count = temp.getNumberUsed( );
    for (index = 0; index < count; index++)
        cout << temp[index] << " ";
    cout << endl;
    cout << "(plus a sentinel value.)\n";
}

void testException(void){
    int cap;
    cout << "Enter capacity of this super array: ";
    cin >> cap;
    PFArrayD temp(cap);
    
    cout << "Enter up to " << cap << " nonnegative numbers.\n";
    cout << "Place a negative number at the end.\n";
    
    double next;
    cin >> next;
    while ((next >= 0) && (!temp.full( )))
    {
        temp.addElement(next);
        cin >> next;
    }
    
    cout << "You entered the following "
    << temp.getNumberUsed( ) << " numbers:\n";
    int index;
    int count = temp.getNumberUsed( );
    for (index = 0; index < count; index++)
        cout << temp[index] << " ";
    cout << endl;
    cout << "(plus a sentinel value.)\n";
    
    int choice;
    do{
        cout << "Choose whether to test exceeding capacity or trying access an out of range index."
             << endl << "(1)Excceed capacity\n(2)Out of range index\n(...)Any other number to exit" << endl;
        cin >> choice;
    
        switch(choice){
            case 1:
                cout << "Now that the array is full, try to add another element.\n Enter an element: ";
                cin >> next;
                try{
                    temp.addElement(next);
                }catch(OutOfRange& full){
                    cout << full.err() << endl;
                    break;
                }
            case 2:
                cout << "The arrays capacity is " << temp.getCapacity() << " try to access an index outside of its range." << endl << "Enter an index: ";
                int i;
                cin >> i;
                cout << "The value at index " << i << " is: ";
            
                try{
                    cout << temp[i] << endl;
                }catch(OutOfRange& out){
                    cout << "There is no value at index " << out.index() << " because " << out.err() << endl;
                }
                break;
            
            default:
                break;
            
        }
    }while(choice == 1 || choice == 2);
    
}
