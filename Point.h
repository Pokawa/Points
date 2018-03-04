//
// Created by pokawa on 3/2/18.
//

#ifndef POINTS_POINT_H
#define POINTS_POINT_H

#include <SFML/Graphics.hpp>

class Point : public sf::CircleShape {
    sf::Vector2f vector;

    void resetVector();
    void resetPosition();

public:
    Point();
    void move(const sf::Time &);
    void wallBounce();
};


#endif //POINTS_POINT_H
