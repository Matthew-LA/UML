#ifndef _UNIVERSE_H
#define _UNIVERSE_H

#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <string>

#include "CelestialBody.h"

using namespace std;

class universe {
    
 public:

  // Loop counter
  void draw(sf::RenderWindow &window1){ 
        
    for (unsigned int i = 0; i < uni.size();i++){ 
            
      window1.draw(uni[i]);
            
      cout << "Loop # " << i << endl;
    }
  }
    
  void pushback(CelestialBody obj){ uni.push_back(obj); } 
    
 private:
    
  vector <CelestialBody> uni;
};

#endif
