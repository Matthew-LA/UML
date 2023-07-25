#ifndef TRIANGLE_HPP
#define TRIANGLE_HPP

#include <cmath>
#include <SFML/Graphics.hpp>

using sf::ConvexShape;
using sf::Vector2f;

class Triangle : public sf::Drawable{
 public:
    Triangle(double initX, double initY, double initL);
 private:
    ConvexShape triangle;
    double x, y;
    double l;
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};

#endif
