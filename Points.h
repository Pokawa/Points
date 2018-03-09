//
// Created by pokawa on 3/2/18.
//

#ifndef POINTS_POINTS_H
#define POINTS_POINTS_H


#include <vector>
#include "Point.h"
#include "config.h"

class Points {
    std::vector<Point> *list;
    sf::RenderWindow * window;
    sf::Clock clock;
    sf::Time elapsed;

    void drawLineBetween(const sf::Vector2f &, const sf::Vector2f &);
    const double distance(const sf::Vector2f &a, const sf::Vector2f &b);

public:
    Points(unsigned int, sf::RenderWindow &);
    void setWindow(sf::RenderWindow &);
    void update();
    void drawPoints();
    void click(const sf::Vector2f &);

    ~Points();
};


#endif //POINTS_POINTS_H
