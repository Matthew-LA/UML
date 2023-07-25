#include <SFML/Graphics.hpp>
#include <iostream>

int main() {
  
  //Make window
  sf::RenderWindow window(sf::VideoMode(400, 400), "SFML works!");
  
  //Load sprite
  sf::Texture texture;
  if(!texture.loadFromFile("sprite.png"))
    return EXIT_FAILURE;
  sf::Sprite sprite(texture);

  //Make the circle
  sf::CircleShape shape(100.f);
  shape.setFillColor(sf::Color::Green);

  while(window.isOpen()) {
    sf::Event event;
    while(window.pollEvent(event)) {
      if(event.type == sf::Event::Closed)
	window.close();
    }

    window.clear();

    float offsetX = 0;
    float offsetY = 0;

    //Get Sprite's current position
    sf::Vector2f pos = sprite.getPosition();
    
    //Move image around screen as long as to not move it off)
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && pos.x != 0)
      offsetX = -1;
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && pos.x != 400 - 198)
      offsetX = 1;
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && pos.y != 0)
      offsetY = -1;
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && pos.y != 400 - 152)
      offsetY = 1;
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::R)) {
      sprite.setPosition(0, 0);
      pos.x = pos.y = 0;
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) 
      window.close();

    //Set a new position
    sprite.setPosition(pos.x + offsetX, pos.y + offsetY);

    //Draw images
    window.draw(shape);
    window.draw(sprite);

    window.display();
  }

  return 0;
}
