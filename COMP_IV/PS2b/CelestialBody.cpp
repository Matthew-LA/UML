#include "CelestialBody.hpp"

#include <iostream>
#include <cmath>


using namespace std;


Universe::Universe(){ 
	
  r = 0; 
  winsize = 0; 
}

Universe::Universe(double radius, int window, int num_of_planets, istream &in){

  int i; 
	
  r = radius; 
  winsize = window;  
  numplanets = num_of_planets; 
  
  for (i = 0; i < num_of_planets; i++){ 
    
    unique_ptr <CelestialBody> ptr(new CelestialBody()); 
    
    CelestialBody();  
    planets.push_back(move(ptr)); 
    planets[i]->set_radius(r); 
    planets[i]->set_window(window); 
    in >> *planets[i]; 
  }

}

void Universe::draw(sf::RenderTarget &target, sf::RenderStates states) const { 

  int i;

  for (i = 0; i < numplanets; i++){ 
    target.draw(*planets.at(i), states); 
  }
}


void Universe::step(double seconds){

  int i, k; 
	
  double ax; 
  double ay;

  double dx; 
  double dy;

  double force; 
  double forcex;
  double forcey;
	
  double fx; 
  double fy;

  double G; 
	
  double velx; 
  double vely;

  double x2;
  double y2;
	
  double r; 

  for (i = 0; i < numplanets; i++){  
    fx = 0; 
    fy = 0; 
		
    for (k = 0; k < numplanets; k++){ 
		  
      if (k != i){
				
	G = 6.67e-11; // gravitational constant
				
	dx = planets[k]->get_posx() - planets[i]->get_posx(); 
	dy = planets[k]->get_posy() - planets[i]->get_posy(); 
				
	r = sqrt(pow(dx, 2) + pow(dy, 2)); 
				
	force = (G * planets[k]->get_mass() * planets[i]->get_mass())/ pow(r, 2); 
	forcex = force * (dx / r);
	forcey = force * (dy / r);

	fy += forcey; 
	fx += forcex;
				
      }
    }

    ax = fx / planets[i]->get_mass(); 
    ay = fy / planets[i]->get_mass(); 
    
    velx = planets[i]->get_velx() + seconds * ax;
    vely = planets[i]->get_vely() + seconds * ay;
		
    planets[i]->set_velx(velx);
    planets[i]->set_vely(vely);
		
    x2 = (planets[i]->get_posx()) + velx * seconds;
    y2 = (planets[i]->get_posy()) + vely * seconds;
		
    planets[i]->set_x_y_pos(x2, y2);
  }
}

void Universe::printInfo(){ 

  int i; // for loop

  cout << numplanets << endl; 
  cout << r << endl; 
  for (i = 0; i < numplanets; i++){ 
    cout << planets[i]->get_posx() << " " << planets[i]->get_posy() << " " << planets[i]->get_velx() << " " << planets[i]->get_vely() << " " << planets[i]->get_mass() << " " << planets[i]->get_filename() << endl;
  } // print out x pos, y pos, velx, vely, mass, and name
}

double Universe::get_r(){ return r; } 

int Universe::get_numPlanets(){ return numplanets; } 

CelestialBody::CelestialBody(){ 
	
  winsize = 0;
  xpos = 0;
  ypos = 0;
  xvel = 0;
  yvel = 0; 
  mass = 0;
  radius = 0;  
  filename = ""; 
}

CelestialBody::CelestialBody(double x_pos, double y_pos, double x_vel, double y_vel, double m, string name, double rad, double window_size){

  double radx;
  double rady;
	
  xpos = x_pos; // updated values of xpos
  ypos = y_pos; // updated values of ypos
  xvel = x_vel; // updated values of xvel
  yvel = y_vel; // updated values of yvel
	
  mass = m; // update mass
  radius = rad; // update radius
  winsize = window_size; // update window size
  filename = name; // update filename

  radx = (winsize / 2) * (xpos / radius) + (winsize / 2); 
  rady = (winsize / 2) * (ypos / radius) + (winsize / 2);


  texture.loadFromFile(filename);  


  sprite.setTexture(texture);
  sprite.setPosition(radx, rady);
}

istream &operator >>(istream &in, CelestialBody &ci){

  double radx;
  double rady;
	
  in >> ci.xpos >> ci.ypos >> ci.xvel >> ci.yvel >> ci.mass >> ci.filename;
	
  radx = (ci.winsize / 2) * (ci.xpos / ci.radius) + (ci.winsize / 2);
  rady = (ci.winsize / 2) * (ci.ypos / ci.radius) + (ci.winsize / 2);

  ci.texture.loadFromFile(ci.filename);  
    
  ci.sprite.setTexture(ci.texture); 
  ci.sprite.setPosition(radx, rady);


  return in; // return input
}

void CelestialBody::draw(sf::RenderTarget &target, sf::RenderStates states) const { target.draw(sprite, states); } 

CelestialBody::~CelestialBody(){} 

double CelestialBody::get_posx(){ return xpos; } // return the xpos
double CelestialBody::get_posy(){ return ypos; } // return the ypos
double CelestialBody::get_velx(){ return xvel; } // return the xvel
double CelestialBody::get_vely(){ return yvel; } // return the yvel
double CelestialBody::get_mass(){ return mass; } // return the mass

string CelestialBody::get_filename(){ return filename; } 

void CelestialBody::set_radius(double r){ radius = r; } 
void CelestialBody::set_window(double size){ winsize = size; } 
void CelestialBody::set_velx(double vx){ xvel = vx; } 
void CelestialBody::set_vely(double vy){ yvel = vy; } 
void CelestialBody::set_x_y_pos(double x_input, double y_input){ 

  double radx; 
  double rady;
	
  xpos = x_input; 
  ypos = y_input; 
	
  radx = (winsize / 2) * (xpos / radius) + (winsize / 2);  
  rady = (winsize / 2) * (-ypos / radius) + (winsize / 2); 
	
  sprite.setPosition(sf::Vector2f(radx, rady)); 
}
