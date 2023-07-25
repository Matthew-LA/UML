#include <iostream>
#include <SFML/Graphics.hpp>
#include "Triangle.hpp"

using std::cout;
using std::endl;
using std::stod;
using sf::RenderWindow;
using std::stoi;

void triangleFractal(int i, RenderWindow* window,
    double x, double y, double l) {

    Triangle triangle(x, y, l);
    window->draw(triangle);
    if (i > 0) {
        triangleFractal(i - 1, window, x - (l / 4),
            y - sqrt((3.0/16) * pow(l, 2)), l/2);
        triangleFractal(i - 1, window, x + l, y, l/2);
        triangleFractal(i - 1, window, x, y + sqrt(.75 * pow(l, 2)), l/2);
    }
    return;
}

int main(int argc, char* argv[]) {
    // sets up command line arguments
    if (argc != 3) {
        cout << "Incorrect number of inputs." << endl;
        exit(1);
    }
    int N = stoi(argv[2]);
    double L = stod(argv[1]);
    if (L <= 0 || N <= 0) {
        cout << "Incorrect input range." << endl;
    }

    RenderWindow window(sf::VideoMode(L * 3, L * 3), "PS3: Recursive Graphics (Triangle Fractal)");
    // loop to check if closed
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // fractal triangle setup
        window.clear(sf::Color::White);
        triangleFractal(N, &window, L * (9.0/10), L, L);

        window.display();
    }
    return 0;
}
