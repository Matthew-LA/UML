#ifndef EDistance_HPP
#define EDistance_HPP

#include <cstring>
#include <vector>

class EDistance {
public:
  EDistance(std::string _stringA, std::string _stringB);
  void printOpt() const;
  int getEditDistance() const;
  std::string getEditString() const;

private:
  // Input Variables
  std::string stringA;
  std::string stringB;

  // Constructed Variables
  std::vector< std::vector<int> > opt;
  int editDistance;
  std::string editString;

  // Private Functions
  int optDistance();
  std::string alignment() const;
  int penalty(char a, char b);
  int min(int a, int b, int c);
};

#endif
