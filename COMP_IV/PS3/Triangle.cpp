#include "Triangle.hpp"
#include <ctime>
#include <random>

std::random_device rd;
std::mt19937 mt(rd());
std::uniform_int_distribution<int> dist(0, 255);

int offset1 = dist(mt);
int offset2 = dist(mt);
int offset3 = dist(mt);

void Triangle::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(triangle, states);
}

Triangle::Triangle(double initX, double initY, double initL):
        x(initX), y(initY), l(initL) {
    double i = sqrt(.75 * pow(l, 2));
    triangle.setPointCount(3);
    triangle.setPoint(0, Vector2f(static_cast<float>(0),
        static_cast<float>(0)));
    triangle.setPoint(1, Vector2f(static_cast<float>(l),
        static_cast<float>(0)));
    triangle.setPoint(2, Vector2f(static_cast<float>(l/2),
    static_cast<float>(i)));
    sf::Color color((time(0) * 5 + offset1) % 256,
        (time(0) * 5 + offset2) % 256, (time(0) * 5 + offset3) % 256);
    triangle.setOutlineColor(color);
    triangle.setOutlineThickness(2);
    triangle.setPosition(x, y);
}
