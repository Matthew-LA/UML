/*                                                                                                                                                                                                
*  Computing IV - Assignment - PS1a                                                                                                                                                               
*  Instructor: Prof. Yelena Rykalova                                                                                                                                                              
*                                                                                                                                                                                                 
*  Due Date: 01/31/22                                                                                                                                                                             
*                                                                                                                                                                                                 
*  Author: Matthew Lorette Anaya                                                                                                                                                                  
*                                                                                                                                                                                                 
*  Description: This program is an implementation of a Fibonacci Linear Feedback Shift Register
                Takes in a seed and generates bits with seed() and numbers with generate(int)
                This is a header file with the FibLFSR class definition.    
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


