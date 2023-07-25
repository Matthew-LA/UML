#ifndef CELESTIALBODY_HPP
#define CELESTIALBODY_HPP

#include <iostream>
#include <string>
#include <vector>
#include <memory>

#include <SFML/Graphics.hpp>

using namespace std;


class CelestialBody :public sf::Drawable {
    
    private:
    
    double winsize; 
    
    double xpos; 
    double ypos;
    
    double xvel;
    double yvel;
    
    double mass;
    double radius;
    
    double display_x;
    double display_y;
    
    string filename;
    
    sf::Sprite sprite;
    sf::Texture texture;

public:
    //constructors
    CelestialBody(); 
    CelestialBody(double x_pos, double y_pos, double x_vel, double y_vel, double m, string name, double radius, double winsize); 
    ~CelestialBody(); 

    friend std::istream& operator >>(std::istream& input, CelestialBody& ci); 
    friend std::ostream& operator <<(std::ostream& out, CelestialBody& co);   

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states)const; 
    
    //accessor functions
    double get_posx(); 
    double get_posy();
    
    double get_velx();
    double get_vely();
    
    double get_mass();
    string get_filename();
    
    //mutators
    void set_x_y_pos(double x_input, double y_input);  
    
    void set_velx(double vx); 
    void set_vely(double vy); 
    
    void set_radius(double radius); 
    void set_window(double size); 
    
    void set_position(); 

};

class Universe : public sf::Drawable { 
    
    public:
    
    Universe(); // basic constructor
    Universe(double radius, int window, int num_of_planets, istream &in); 
    
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states)const; 
    
    friend ostream &operator <<(std::ostream& out, const Universe& co);
    
    void step(double seconds); 
    
    double get_r();
    int get_numPlanets();

    void printInfo();
   
private:
    
    double r;
    
    int numplanets;
    int winsize;
    
    vector <std::unique_ptr <CelestialBody>> planets;

};

#endif 