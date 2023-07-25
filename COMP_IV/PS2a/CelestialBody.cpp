#include "CelestialBody.h"

CelestialBody::CelestialBody() { return; }

CelestialBody::CelestialBody(double x_position, double y_position, double x_velocity, double y_velocity, double bmass, string planet) {

  // Define everything
  sf::Sprite draw_plan; 
	
  // Set new positions in reference to the old
  xpos = x_position; 
	
  ypos = y_position; 
	
  xvel = x_velocity; 
	
  yvel = y_velocity; 
	
  mass = bmass; 
	
  picture = planet; 
	
  // Return if fail
  if(!pImage.loadFromFile(picture)) { return; } 
	
  // Load the input(s)
  pTexture.loadFromImage(pImage);  
	
  // Load from texture(s)
  pSprite.setTexture(pTexture); 
	
  // Set x and y axis
  xpos = ((window.x/radius) * xpos/2) + (window.x / 2);  
  ypos = ((window.y/radius) * ypos/2) + (window.y / 2); 
	
  // Set position using x and y values
  pSprite.setPosition(sf::Vector2f(xpos,ypos)); 
	
  // Print values
  cout << xpos << endl << ypos << endl; 
}

void CelestialBody::draw(sf::RenderTarget &obj, sf::RenderStates status) const { obj.draw(pSprite); }

ostream &operator <<(ostream &output, CelestialBody &c) { 
	
  output << "current x Position: " << c.xpos << endl; 
	
  output << "current y Postion: " << c.ypos << endl;  
	
  output << "current x Velocity: " << c.xvel << endl; 
	
  output << "current y Velocity: " << c.yvel << endl; 
	
  output << "Particle Mass: " << c.mass << endl;  
	
  output << "Particle Name: " << c.picture << endl; 
	
  return output; 
}

istream &operator >>(istream &input, CelestialBody &d) {

  //Get the positions, velocity, mass, and picture
  input >> d.xpos >> d.ypos >> d.xvel >> d.yvel >> d.mass >> d.picture; 
        
  if(!d.pImage.loadFromFile(d.picture)) { cout << "Error! Something went wrong while loading the file..." << endl; } 
        
  // Load .gif files
  d.pTexture.loadFromImage(d.pImage); 
        
  // Set the textures 
  d.pSprite.setTexture(d.pTexture);
        
  d.xpos = ((window.x/radius) * d.xpos/2) + (window.x / 2);  
  
  d.ypos = ((window.y/radius) * d.ypos/2) + (window.y / 2);
        
  d.pSprite.setPosition(sf::Vector2f(d.xpos, d.ypos)); 
        
  return input; 
}
