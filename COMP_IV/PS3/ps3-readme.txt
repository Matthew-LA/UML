/**********************************************************************
 *  ps3-readme 
 *  Recursive Graphics (Triangle Fractal)                       
 **********************************************************************/

Your name: Matthew Lorette Anaya

Hours to complete assignment: 4

/**********************************************************************
 *  Briefly discuss the assignment itself and what you accomplished.
 **********************************************************************/
The project contains an object that holds all the information for each 
individual triangle. Main.cpp then uses a recursive function to print them 
All out in a pascal triangle.

Input ranges(suggested):
	length(L): 100-300

	recursion depth(N): 1-10
	

 /**********************************************************************
 *  Discuss one or more key algorithms, data structures, or 
 *  OO designs that were central to the assignment.
 **********************************************************************/
Recursion is literally the name of the game here within this project. It 
allows the triangles to be printed to pascals form without manual input or more
tedious loops.

Vectors are also a godsend when it comes to memory management, which can be a 
nightmare if the changing of an objects "size" is needed or leaks are allowed to happen. 

/**********************************************************************
 *  Briefly explain the workings of the features you implemented.
 *  Include code excerpts.
 **********************************************************************/

Triangle::Triangle(double initX, double initY, double initL):
        x(initX), y(initY), l(initL) {
    double i = sqrt(.75 * pow(l, 2));
    triangle.setPointCount(3);
    triangle.setPoint(0, Vector2f(static_cast<float>(0),
        static_cast<float>(0)));
    triangle.setPoint(1, Vector2f(static_cast<float>(l),
        static_cast<float>(0)));
    triangle.setPoint(2, Vector2f(static_cast<float>(l/2),
    static_cast<float>(i)));
    sf::Color color((time(0) * 5 + offset1) % 256,
        (time(0) * 5 + offset2) % 256, (time(0) * 5 + offset3) % 256);
    triangle.setOutlineColor(color);
    triangle.setOutlineThickness(2);
    triangle.setPosition(x, y);

This function is pretty much the whole project. It sets the size, thickness, and color of 
the triangles to be printed by main.


 /**********************************************************************
 *  Briefly explain what you learned in the assignment.
 **********************************************************************/
That recursion is a really powerful tool, but can be extremly taxing if not
implemented properly.


/**********************************************************************
 *  List whatever help (if any) you received from the instructor,
 *  classmates, or anyone else.
 **********************************************************************/



/**********************************************************************
 *  Describe any serious problems you encountered.  
 *  If you didn't complete any part of any assignment, 
 *  the things that you didn't do, or didn't get working.                  
 **********************************************************************/



/**********************************************************************
 *  List any other comments here.                                     
 **********************************************************************/
