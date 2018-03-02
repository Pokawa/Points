//
// Created by pokawa on 3/2/18.
//

#include "Points.h"

Points::Points(unsigned int a) {
    this->list = new std::vector<Point>(a);
    this->list->shrink_to_fit();
}

Points::Points() {
    this->list = new std::vector<Point>(100);
    this->list->shrink_to_fit();
}

void Points::draw(sf::RenderWindow &window) {
    auto i = this->list->begin();
    do {
        window.draw(*i);
    } while (++i < this->list->end());
}

void Points::move() {
    auto i = this->list->begin();
    do {
        i->move();
    } while (++i < this->list->end());
}
