// Dr. Rykalova
// test.cpp for PS1a
// updated 1/31/2020

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
                This is the test file with BOOST unit tests.
*/


#include <iostream>
#include <string>

#include "FibLFSR.h"

#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE Main
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(sixteenBitsThreeTaps) {

  FibLFSR l("1011011000110110");
  BOOST_REQUIRE(l.step() == 0);
  BOOST_REQUIRE(l.step() == 0);
  BOOST_REQUIRE(l.step() == 0);
  BOOST_REQUIRE(l.step() == 1);
  BOOST_REQUIRE(l.step() == 1);
  BOOST_REQUIRE(l.step() == 0);
  BOOST_REQUIRE(l.step() == 0);
  BOOST_REQUIRE(l.step() == 1);

  FibLFSR l2("1011011000110110");
  BOOST_REQUIRE(l2.generate(9) == 51);
}

  // Test case that prints out the starting and the resulting bit
  // patterns whilst checking to make sure the correct result is printed
BOOST_AUTO_TEST_CASE(customTestCase1) {
  std::cout << "\n------Custon Test Case 1------" << std::endl;
  FibLFSR l("1011011000110110");
  std::cout << "\tOriginal seed: " << l << std::endl;

  int res = l.generate(5);
  BOOST_REQUIRE(res == 3);

  std::cout << "Results of generate(5): " << l << " " << res << std::endl;
  std::cout << std::endl;
}

BOOST_AUTO_TEST_CASE(customTestCase2) {
  std::cout << "\n------Custon Test Case 2------" << std::endl;

  std::string tooShort = "10010110";
  std::string tooLong = "10011001001010101101";

  std::cout << "Test exception thrown for too short seed: 10010110" << std::endl;
  BOOST_REQUIRE_THROW(FibLFSR("10010110"), std::invalid_argument);

 std::cout << "Test exception thrown for too long seed: 10011001001010101101" << std::endl;
 BOOST_REQUIRE_THROW(FibLFSR("10011001001010101101"), std::invalid_argument);
}
  
