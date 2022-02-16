 /***********************************************
 Author:Matthew Lorette Anaya
 Date: 09/20 /2020
 Purpose: Using a class to manipulate points on a cartesian plane
 Sources of Help: class recordings
 Time Spent: 45 mins
  
Computing III -- COMP.2010 Honor Statement
The practice of good ethical behavior is essential for maintaining good order in the classroom, providing an enriching learning experience for students, and as training as a practicing computing professional upon graduation. This practice is manifested in the University’s Academic Integrity policy. Students are expected to strictly avoid academic dishonesty and adhere to the Academic Integrity policy as outlined in the course catalog. Violations will
be dealt with as outlined therein.
I certify that the work submitted with this assignment is mine and was generated in a manner consistent with this document, the course academic policy on the course website on Blackboard, and the UMass Lowell academic code.
  Date: 09/20/2020
  Name: Matthew Lorette Anaya
 ***********************************************/
#include <iostream>

using namespace std;

class Point{
public:
    //default constructor
    Point(){
        x = 0;
        y = 0;
    }
    //parameterized constructor
    Point(int x, int y){
        Point::x = x;
        Point:: y = y;
    }
    //function to set axis of the point by input after object creation
    // x = x axis, y = y axis
    void set_point(int x, int y){
        Point::x = x;
        Point::y = y;
    }
    //function to move point by user input
    //mx moves x axis left or right
    //my moves y axis up or down
    void move_point(int mx, int my){
        x = x + mx;
        y = y + my;
    }
    //function to rotate point by 90 degrees clockwise around origin
    // formula for rotating clockwise , x' = x*cos(90) + y*sin(90) = y (since cos(90) = 0 and sin(90) =1) y'=y*cos(90) - x*sin(90) = -x
    void rotate(){
        int temp = x;
        x = y;
        y = -temp;
    }
    //function to get value of x
    int get_x(){
        return x;
    }
    //function to get value of y
    int get_y(){
        return y;
    }
private:
    //data members
    int x,
        y;
    
    
};

int main(int argc, const char * argv[]) {
    
    Point p1,
          p2,
          p3,
          inputP;
    
    int i,
        inputX,
        inputY,
        numOfRotate;
    
    char choice;
    /*
    p1.set_point(1,2);
    cout << "Point 1 is: (" << p1.get_x() <<", " << p1.get_y() << ")" << endl;
    for(i = 1; i <= 4; i++){
        p1.rotate();
        cout << "After " << i << " rotation(s) point 1 is: (" << p1.get_x() << ", " << p1.get_y() << ")" << endl;
    }
    
    p2.set_point(3,4);
    cout << "Point 2 is: (" << p2.get_x() << ", " << p2.get_y() << ")" << endl << "When moved: (1, 1)" << endl;
    p2.move_point(1,1);
    cout << "Point 2 is now: (" << p2.get_x() << ", " << p2.get_y() << ")" << endl;
    
    p3.set_point(5, -4);
    cout << "Point 3 is: (" << p3.get_x() << ", " << p3.get_y() << ")" << endl << "When moved: (-5, 4)" << endl;
    p3.move_point(-5, 4);
     cout << "Point 3 is now: (" << p3.get_x() << ", " << p3.get_y() << ")" << endl;
    */
    
    cout << "Enter a point you would like to manipulate." << endl << "X axis: ";
    cin >> inputX;
    cout << "Y axis: ";
    cin >> inputY;
    inputP.set_point(inputX, inputY);
    
    do{
        cout << "Enter R/r to rotate the point or M/m to move the point. Enter any other character to quit." << endl;
        cin >> choice;
        
        //rotate the point amount specified by user
        if(choice == 'R' || choice == 'r'){
            cout << "Enter how many times you would like to rotate the point 90 degrees : ";
            cin >> numOfRotate;
            for(i = 0; i < numOfRotate; i++){
                inputP.rotate();
            }
            cout << "The point is now: (" << inputP.get_x() << ", " << inputP.get_y() << ")" << endl;
        }
        //move point specified by user
        else if(choice == 'M' || choice == 'm'){
            cout << "Enter a negative number to move the X axis left. Enter a positive number to move the X axis to the right." << endl << "Enter X axis: ";
            cin >> inputX;
            cout << "Enter a negative number to move the Y axis down. Enter a positive number to move the Y axis up." << endl << "Enter Y axis: ";
            cin >> inputY;
            inputP.move_point(inputX, inputY);
            cout << "The point is now: (" << inputP.get_x() << ", " << inputP.get_y() << ")" << endl;
        }
        else{
            exit(1);
        }
    }while(choice == 'M' || choice == 'm' || choice == 'R' || choice == 'r');
    
    
    return 0;
}
