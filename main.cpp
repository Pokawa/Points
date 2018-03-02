#include <iostream>
#include "SFML/Graphics.hpp"
#include "config.h"
#include "Points.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "SFML");
    srand((unsigned)(time(nullptr)));
    Points points(POINTS);
    while (window.isOpen())
    {
        sf::Event event{};
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        points.update();
        points.drawPoints(window);
        window.display();
    }
    return 0;
}