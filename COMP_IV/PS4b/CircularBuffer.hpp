// Copyright 2022 Matthew Lorette Anaya, matthew_loretteanaya@student.uml.edu

#ifndef _USERS_MATTHEWLORETTEANAYA_DOCUMENTS_UML_COMP_IV_PS4B_CIRCULARBUFFER_HPP_
#define _USERS_MATTHEWLORETTEANAYA_DOCUMENTS_UML_COMP_IV_PS4B_CIRCULARBUFFER_HPP_

#include <stdint.h>
#include <iostream>
#include <string>
#include <sstream>
#include <exception>
#include <stdexcept>
#include <vector>

class CircularBuffer {
 public:
// create an empty circular buffer, with given max capacity
  explicit CircularBuffer(int capacity);
  int size();
  bool isEmpty();
  bool isFull();
  void enqueue(int16_t x);
  int16_t dequeue();
  int16_t peek();
  void output();

 private:
  std::vector<int16_t> buff;
  int first;
  int last;
  int cap;
  int s;
};

#endif  // _USERS_MATTHEWLORETTEANAYA_DOCUMENTS_UML_COMP_IV_PS4B_CIRCULARBUFFER_HPP_
