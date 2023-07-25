#ifndef _CELESTIALBODY_H
#define _CELESTIALBODY_H

#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <string>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

using namespace std;

const sf::Vector2f window(500,500);
const double radius = 2.50e11;

class CelestialBody: public sf::Drawable {
    
 public:
    
  CelestialBody();

  // Helps with positioning
  CelestialBody(double x_position, double y_position, double x_velocity, double y_velocity, double bmass, string planet);

  void draw(sf::RenderTarget &obj, sf::RenderStates status) const;
    
  friend ostream &operator <<(ostream &output, CelestialBody &c); 
  friend istream &operator >>(istream &input, CelestialBody &d);  
    
 private:
    
  double mass;
    
  double xpos;
  double ypos;
    
  double xvel;
  double yvel;
    
  string picture;
    
  sf::Image pImage;  
  
  sf::Sprite pSprite; 
    
  sf::Texture pTexture; 
};

#endif
