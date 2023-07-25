#ifndef STRINGSOUND_HPP
#define STRINGSOUND_HPP

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <cmath>
#include <iostream>
#include <string> 
#include <vector>
#include "CircularBuffer.hpp"

const int SAMPLING_RATE = 44100;
const double ENERGY_DECAY_FACTOR = 0.996;

class StringSound {
 public:
  explicit StringSound(double frequency);

  explicit StringSound(std::vector<sf::Int16> init);

  void pluck();

  // advance the simulation one time step
  void tic();  
  
  // return the current sample            
  sf::Int16 sample();
  
  // return number of times tic was called      
  int time();              

 private:
  CircularBuffer buff;
  int num;
  int tictic;
};
#endif
