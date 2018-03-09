//
// Created by pokawa on 3/2/18.
//

#ifndef POINTS_POINT_H
#define POINTS_POINT_H

#include <SFML/Graphics.hpp>

class Point : public sf::CircleShape {
    sf::Vector2f vector;

    double distance;
    sf::Vector2f runVector;

    void resetVector();
    void resetPosition();
    const double move(const sf::Vector2f &, const double &);


public:
    Point();
    void wallBounce();
    void update(const sf::Time &);
    void setRun(const sf::Vector2f &, const double &);
};


#endif //POINTS_POINT_H
