//
// Created by pokawa on 3/2/18.
//

#ifndef POINTS_POINTS_H
#define POINTS_POINTS_H


#include <vector>
#include "Point.h"

class Points {
    std::vector<Point> *list;

public:
    explicit Points(unsigned int a);
    void update();
    void draw(sf::RenderWindow &window);


    ~Points();
};


#endif //POINTS_POINTS_H
