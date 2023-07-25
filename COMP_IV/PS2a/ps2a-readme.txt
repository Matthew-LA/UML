/**********************************************************************
 *  N-Body Simulation ps2a-readme.txt template
 **********************************************************************/

Name: Matthew Lorette Anaya
Hours to complete assignment: 5 hours

/**********************************************************************
 *  Briefly discuss the assignment itself and what you accomplished.
 **********************************************************************/

The goal of this assignment was to create an SFML window and fill it with the contents of planets.txt using two classes, Universe and CelestialBody. 
Universe is a class which contains a vector of CelestialBody(s) and also has a function to draw the planets by accessing a vector.
For extra credit, I added a background image called "A Small Glimpse of The Cosmos:" and used smart pointers to avoid data leaks.

  /**********************************************************************
 *  Discuss one or more key algorithms, data structures, or 
 *  OO designs that were central to the assignment.
 **********************************************************************/

The class Universe was a vector of CelestialBody which was used to hold all the planets that were fed into the program from planets.txt.

/**********************************************************************
 *  Briefly explain the workings of the features you implemented.
 *  Describe if and how do you used the smart pointers 
 *  Include code excerpts.
 **********************************************************************/

unique_ptr <universe> u(new universe());
 
 I used a smart pointer to represent the universe, closing off the possibilities of memory issues. The universe was allocated through the following for loop:
 
 for(i = 0; i < bodies; i++){
      
      body = new CelestialBody();
      
      cin >> *body;
      
      (*u).pushback(*body);
      
      cout << *body;
    }
	
I had to make a pushback function in order to assign CelestialBody(s) to the vector.



/**********************************************************************
 *  List whatever help (if any) you received from the instructor,
 *  classmates, or anyone else.
 **********************************************************************/


/**********************************************************************
 *  Describe any serious problems you encountered.                    
 **********************************************************************/


/**********************************************************************
 *  List any other comments here.                                     
 **********************************************************************/
