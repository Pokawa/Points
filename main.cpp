#include <iostream>
#include "SFML/Graphics.hpp"
#include "config.h"
#include "Points.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "SFML");

    srand((unsigned)(time(nullptr)));

    sf::Clock clock;
    sf::Time elapsed = clock.restart();
    Points points(POINTS, window);

    while (window.isOpen())
    {
        sf::Event event{};
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        elapsed = clock.restart();
        points.update(elapsed);
        points.drawPoints();
        window.display();
    }
    return 0;
}