#include <iostream>
#include "SFML/Graphics.hpp"
#include "config.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "SFML");
    srand((unsigned)(time(nullptr)));

    while (window.isOpen())
    {
        sf::Event event{};
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.display();
    }
    return 0;
}