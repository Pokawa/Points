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

    void drawLineBetween(sf::RenderWindow &, sf::Vector2f, sf::Vector2f);


public:
    explicit Points(unsigned int a);
    void update();
    void drawPoints(sf::RenderWindow &window);


    ~Points();
};


#endif //POINTS_POINTS_H
