/*
Computing IV - Assignment - PS1a + b
Instructor: Prof. Yelena Rykalova
Due Date: 02/07/22
Author: Matthew Lorette Anaya
Description: This program is an implementation of a Fibonacci Linear Feedback                Shift Register
             This is a header file with the FibLFSR class definition
*/
   
#include <iostream>

class FibLFSR {
  
 public:
  FibLFSR(std::string seed);
  
  int step();

  int generate(int k);

  friend std::ostream& operator<<(std::ostream& os, FibLFSR &lfsr);

 private:
  std::string reg;
  
  int getBit(char a);
  
  int xOr(int a, int b);
  
};


