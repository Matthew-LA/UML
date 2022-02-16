/***********************************************
 Author: Matthew Lorette Anaya
 Date: 10/20/2020
 Purpose: Using class' to copy a vectors behavior
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
 Date: 10/20/2020
 Name: Matthew Lorette Anaya
*/

#include <iostream>
#include <string>

using namespace std;

class DynamicStringArray{
public:
    DynamicStringArray();
    DynamicStringArray(DynamicStringArray& iObj);
    ~DynamicStringArray();
    int getSize()const;
    void addEntry(const string input);
    bool deleteEntry(const string input);
    string getEntry(const int entry);
    DynamicStringArray & operator=(const DynamicStringArray& iObj);
    friend ostream &operator<<(ostream &out, const DynamicStringArray& iObj);

private:
    int size;
    string* dynamicArray;
};
ostream &operator<<(ostream &out, const DynamicStringArray& iObj);

int main(int argc, char* argv[]){
    
    DynamicStringArray dArr1;
    dArr1.addEntry("Ashley");
    dArr1.addEntry("Elizabeth");
    dArr1.addEntry("Cali");
    cout << "DynamicString Array1\n--------------------\n" << dArr1 << "Size:\n\t" << dArr1.getSize() << endl << "after adding Ashley, Elizabeth, and Cali.\n\n";
    
    DynamicStringArray dArr2(dArr1);
    cout << "DynamicString Array2\n--------------------\n" << dArr2 << "Size:\n\t" << dArr2.getSize() << endl << "after using the copy constructor.\n\n";
    dArr2.deleteEntry("Cali");
    cout << "DynamicString Array2\n--------------------\n" << dArr2 << "Size:\n\t" << dArr2.getSize() << endl << "after deleting \"Cali\".\n\n";
    
    DynamicStringArray dArr3 = dArr2;
    cout << "DynamicString Array3\n--------------------\n" << dArr3 << "Size:\n\t" << dArr3.getSize() << endl << "after using the copy overload function with dArr2 as the right operrand.\n\n";
    dArr3.addEntry("John");
    cout << "DynamicString Array3\n--------------------\n" << dArr3 << "Size:\n\t" << dArr3.getSize() << endl << "after adding \"John\"." << endl;
    cout << "The name after calling \"getEntry\" at position 2: " << dArr3.getEntry(1) <<endl;
    //commented out for a smooth for run
    //cout << "The name after calling \"getEntry\" at position 3 whic is out of bounds: " << dArr3.getEntry(3) <<endl;
    
    
    
    dArr1.~DynamicStringArray();
    dArr2.~DynamicStringArray();
    dArr3.~DynamicStringArray();
    
    return 0;
}
//Default constructor initializing size to zero and
//a string pointer to null pointer.
DynamicStringArray::DynamicStringArray(){
    size = 0;
    dynamicArray = nullptr;
}
//Constructor that initializes a new object with an existing object
DynamicStringArray::DynamicStringArray(DynamicStringArray& iObj){
    int i;
    
    dynamicArray = new string[iObj.size];
    size = iObj.size;
    for(i = 0; i < size; i++){
        dynamicArray[i] = iObj.dynamicArray[i];
    }
    
}
//object destructor
DynamicStringArray::~DynamicStringArray(){
    delete[] dynamicArray;
    size = 0;
    dynamicArray = nullptr;
}
//member function to return the size of the object
int DynamicStringArray::getSize()const{
    return size;
}
//member function to add a string into an existing object
//by creating a new object incrementing it's size by one, copying
//the existing object and adding the string input to the end.
//Then assigning the old string pointer to the new object.
void DynamicStringArray::addEntry(const string input){
    string* newArr = new string[size+1];
    int i;
    
    for(i = 0; i < size; i++){
        newArr[i] = dynamicArray[i];
    }
    newArr[i] = input;
    size++;
    delete[] dynamicArray;
    dynamicArray = newArr;
}
//member function to delete a string input
//if the string is found within the object, create a new
//object one size smaller, copy existing object to new object
//excluding the string input and return true.
//Otherwise return false if the string input was not found.
bool DynamicStringArray::deleteEntry(const string input){
    int i,
        at = 0,
        count = 0;
    bool found = false;
    
    //if the string input is found, at variable holds the position of
    //string input and found variable is true
    for(i = 0; i < size; i++){
        if(dynamicArray[i] == input){
            at = i;
            found = true;
            break;
        }
    }
    //if string input is found within the object
    //create new object and copy exisiting excluding
    //the string input. when the postion of the string input
    //is found skip a loop iteration to avoid copying it into
    //new string. i variable holds the existing objects position.
    //count holds the new objects position.
    if(found){
        string* newArr = new string[size-1];
        for(i = 0; i < size; i++){
            if(i == at){
                continue;
            }
            else{
                newArr[count++] = dynamicArray[i];
            }
        }
        size--;
        delete[] dynamicArray;
        dynamicArray = newArr;
        return true;
    }
    else{
        return false;
    }
        
           
}
//member function to return a string at the inputs
//postion. if the position is out of bounds, print error
//message and return a nullptr.
string DynamicStringArray::getEntry(const int entry){
    if(entry >= size){
        cout << "That index is out of the array's bounds" << endl;
        return nullptr;
    }
    else{
        return dynamicArray[entry];
    }
}
//overloaded copy assignment operator.
DynamicStringArray & DynamicStringArray::operator=(const DynamicStringArray& iObj){
    int i, size;
    
    if(dynamicArray != iObj.dynamicArray){
        delete[] dynamicArray;
        dynamicArray = new string[iObj.size];
        size = iObj.size;
        for(i = 0; i < size; i ++){
            dynamicArray[i] = iObj.dynamicArray[i];
        }
    }
    return *this;
}
//overloaded ostream operator
ostream &operator<<(ostream &out, const DynamicStringArray& iObj){
    int i;
    
    out << "Names: " << endl;
    for(i = 0; i < iObj.size; i++){
        out << "\t" << iObj.dynamicArray[i] << endl;
    }
    
    return out;
}
