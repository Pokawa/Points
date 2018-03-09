#include <iostream>
#include "SFML/Graphics.hpp"
#include "config.h"
#include "Points.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "SFML");

    srand((unsigned)(time(nullptr)));

    Points points(POINTS, window);

    while (window.isOpen())
    {
        sf::Event event{};
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            if (event.type == sf::Event::MouseButtonPressed)
            {
                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    sf::Vector2f mouse(event.mouseButton.x, event.mouseButton.y);
                    points.click(mouse);
                }
            }

        }

        window.clear();
        points.update();
        points.drawPoints();
        window.display();
    }
    return 0;
}