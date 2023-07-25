#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE Main
#include <boost/test/unit_test.hpp>

#include <vector>
#include <exception>
#include <stdexcept>

#include "StringSound.hpp"

BOOST_AUTO_TEST_CASE(GS)
{
  std::vector<sf::Int16> v;
  v.push_back(0);
  v.push_back(2000);
  v.push_back(4000);
  v.push_back(-10000);

  BOOST_REQUIRE_NO_THROW(StringSound ss = StringSound(v));

  StringSound ss = StringSound(v);
  
  // StringSound = 0 2000 4000 -10000
  BOOST_REQUIRE(ss.sample() == 0);

  // StringSound = 2000 4000 -10000 996
  ss.tic();
  BOOST_REQUIRE(ss.sample() == 2000);

  // StringSound = 4000 -10000 996 2988
  ss.tic();
  BOOST_REQUIRE(ss.sample() == 4000);

  // StringSound = -10000 996 2988 -2988
  ss.tic();
  BOOST_REQUIRE(ss.sample() == -10000);

  // StringSound = 996 2988 -2988 -4483
  ss.tic();
  BOOST_REQUIRE(ss.sample() == 996);

  // StringSound = 2988 -2988 -4483 1984
  ss.tic();
  BOOST_REQUIRE(ss.sample() == 2988);

  // StringSound = -2988 -4483 1984 0
  ss.tic();
  BOOST_REQUIRE(ss.sample() == -2988);

  //more
  ss.tic();
  BOOST_REQUIRE(ss.sample() == -4483);
  ss.tic();
  BOOST_REQUIRE(ss.sample() == 1984);
  ss.tic();
  BOOST_REQUIRE(ss.sample() == 0);
}
