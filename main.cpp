#include <iostream>
#include "SFML/Graphics.hpp"
#include "config.h"
#include "Points.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "SFML");
    srand((unsigned)(time(nullptr)));
    Points points;
    while (window.isOpen())
    {
        sf::Event event{};
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        points.move();
        points.draw(window);
        window.display();
    }
    return 0;
}