#include <iostream>
#include <cstring>
#include <SFML/System.hpp>

#include "EDistance.hpp"

using namespace std;

int main() {

  // Clock
  sf::Clock clock;
  sf::Time t;

 
  string String1;
  string String2;

  // Get input
  cin >> String1;
  cin >> String2;
  
  // Initialize my class, all math done in constructor and sets relevant
  // member variables
  EDistance output(String1, String2);


  // Get desired output
  cout << "Edit distance = " << output.getEditDistance() << endl;
  cout << output.getEditString() << endl;

  t = clock.getElapsedTime();
  cout << "Execution time is " << t.asSeconds() << " seconds." << endl;

  return 0;
}
