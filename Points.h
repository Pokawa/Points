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

    void drawLineBetween(sf::Vector2f, sf::Vector2f);


public:
    explicit Points(unsigned int a);
    Points(unsigned int a, sf::RenderWindow &window);
    void setWindow(sf::RenderWindow &window);
    void update();
    void drawPoints();


    ~Points();
};


#endif //POINTS_POINTS_H
