#include <string>
#include <iostream>

#include "CelestialBody.h"
#include "Universe.h"

using namespace std;

int main(int argc,char *argv[]){
    
    int i, bodies; 
    double radius;

    CelestialBody *body;

    sf::Image backgroundimage;
    sf::Texture background_texture;
    sf::Sprite background_sprite;
    
    sf::RenderWindow window1(sf::VideoMode(500, 500), "A Small Glimps of The Cosmos:");
    
    backgroundimage.loadFromFile("starfield.jpg");
    
    background_texture.loadFromImage(backgroundimage); 
    
    background_sprite.setTexture(background_texture);
    
    cout << scientific;

    cin >> bodies >> radius;
    
    window1.draw(background_sprite);
    
    window1.display();
    
    cout << "Input: " << bodies << " radius: " << radius << endl;

    unique_ptr <universe> u (new universe());

    // Loop to allocate space for the Universe and make use of the smart pointer to avoid memory leaks.
    for(i = 0; i < bodies; i++){ 
      
      body = new CelestialBody();
      
      cin >> *body;

      (*u).pushback(*body);
      
      cout << *body;
    }
    
    (*u).draw(window1);
    
    window1.display(); 

    // Kill window once drawing completes
    while (window1.isOpen()){ 

      sf::Event event;
      
      while(window1.pollEvent(event)){
        
        if (event.type == sf::Event::Closed) window1.close();
        
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) window1.close(); 

      }
      
      window1.display();
    }
    
    return 0;
}
