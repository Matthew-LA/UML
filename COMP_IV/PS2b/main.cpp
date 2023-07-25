#include <iostream>
#include <cstdlib>
#include <vector>

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>


#include "CelestialBody.hpp"

using namespace std;

int main(int argc, char* argv[]){

    int cbodies;
    
    double dt;
    double radius;
    double T;
    double time;

    string filename;

    sf::Clock clock;
 
    
    if (argc != 3){

        cout << "\nThere are not enough arguments, exiting!" << endl;
        return -1;
    }
    
    time = 0; // start time

    filename = argv[0]; 
    T = strtod(argv[1], NULL);
    dt = strtod(argv[2], NULL);
    
    cin >> cbodies;
    cin >> radius;


    Universe cb(radius, 500, cbodies, cin);

    sf::RenderWindow window(sf::VideoMode(600, 600), "A Small Glimps of The Cosmos:");  

    while (window.isOpen()){
        
        sf::Event event;
        
        while (window.pollEvent(event)){ if (event.type == sf::Event::Closed) window.close(); }
        
        window.clear();
        
        if (time < T){ // as long as time hasn't run out

            sf::Time elapsed = clock.getElapsedTime(); 
            
            cout << "\nElapsed time: " << elapsed.asSeconds( ) << " seconds." << endl;
            
            cb.step(dt);
            
            time += dt;
        }
        
        window.draw(cb);
        window.display();
    }

	return 0;
}