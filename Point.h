//
// Created by pokawa on 3/2/18.
//

#ifndef POINTS_POINT_H
#define POINTS_POINT_H

#include <SFML/Graphics.hpp>

class Point : public sf::CircleShape {
    sf::Vector2f vector;
    const float speed = 0.1;

    void resetVector();

    void resetPosition();

public:
    Point();

    void move();
};


#endif //POINTS_POINT_H
