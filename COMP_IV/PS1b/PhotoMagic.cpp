/*
Computing IV - Assignment - PS1a + b
Instructor: Prof. Yelena Rykalova
Due Date: 02/07/22
Author: Matthew Lorette Anaya
Description: This program is an implementation of a Fibonacci Linear Feedback                Shift Register
             This is the implementation of the PhotoMagic.class which takes thre             e arguments an input image an output image and a seed. The program              uses the the seed to encode the input image and display it as the o             utput image.
*/
#include <iostream>
#include <string>
#include <sstream>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "FibLFSR.h"

void transform( sf::Image& img, FibLFSR* bit_generator) {
  // randomize the bits in the image
  sf::Vector2u imgsize = img.getSize();
  // initialize an SFML pixel
  sf::Color p;

  for(int x = 0; x < (signed)imgsize.x; x++) {
    for(int y = 0; y < (signed)imgsize.y; y++) {
      // get the current pixel from the input image
      p = img.getPixel(x, y);

      // generate encoded pixels
      p.r = p.r ^ bit_generator -> generate(8);
      p.g = p.g ^ bit_generator -> generate(8);
      p.b = p.b ^ bit_generator -> generate(8);

    // edit the image in-place with new encoded pixels
      img.setPixel(x, y, p);
    }
  }
}
int main(int argc, char* argv[]) {
  if(argc != 4) {
    std::cout << "Incorrect Input Format" << std::endl
	      << "Input should be as follows: ./PhotoMagic <inputfilename> <outputfilename> <seed>\n";
    return -1;
  }

  // store input in variables
  std::string input_fname(argv[1]);
  std::string output_fname(argv[2]);
  std::string seed = argv[3];

  // create an LSFR object
  FibLFSR bit_generator(seed);

  // load images
  sf::Image input_image;
  if (!input_image.loadFromFile(input_fname)) {
      return -1;
  }

  sf::Image output_image;
  if (!output_image.loadFromFile(input_fname)) {
      return -1;
  }

  // display 2 windows
  sf::Vector2u imgsize = input_image.getSize();
  sf::RenderWindow input_window(sf::VideoMode(imgsize.x, imgsize.y), "Input Image");
  sf::RenderWindow output_window(sf::VideoMode(imgsize.x, imgsize.y), "Output Image");

  // load the images into textures
  sf::Texture in_texture, out_texture;
  in_texture.loadFromImage(input_image);

  transform(input_image, &bit_generator);

  out_texture.loadFromImage(input_image);

  // load textures -> sprites
  sf::Sprite in_sprite, out_sprite;
  in_sprite.setTexture(in_texture);
  out_sprite.setTexture(out_texture);

  // main loop
  while (input_window.isOpen() && output_window.isOpen()) {
      sf::Event event;

      while (input_window.pollEvent(event)) {
	  if (event.type == sf::Event::Closed) {
	      input_window.close();
	    }
	}

      while (output_window.pollEvent(event)) {
	  if (event.type == sf::Event::Closed) {
	      output_window.close();
	    }
	}

      input_window.clear();
      input_window.draw(in_sprite);    // Input image
      input_window.display();

      output_window.clear();
      output_window.draw(out_sprite);    // Output image
      output_window.display();
    }

  // save the image
  if (!input_image.saveToFile(output_fname)) {
      return -1;
    }
    
  return 0;
}
