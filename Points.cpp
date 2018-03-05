//
// Created by pokawa on 3/2/18.
//

#include "Points.h"

void Points::drawPoints() {
    auto i = list->begin();
    do {
        window->draw(*i);
        drawLineBetween(sf::Vector2f(sf::Mouse::getPosition(*window)), i->getPosition());

        auto j = list->begin();
        do
        {
            drawLineBetween(i->getPosition(), j->getPosition());
        } while (++j < list->end());

    } while (++i < list->end());
}

void Points::update(const sf::Time &elapsed) {
    auto i = list->begin();
    do {
        i->wallBounce();
        i->move(elapsed);
    } while (++i < list->end());
}

Points::~Points() {
    delete list;
}

void Points::drawLineBetween(sf::Vector2f a, sf::Vector2f b) {
    const double x = a.x - b.x;
    const double y = a.y - b.y;
    const double dist = sqrt((x * x) + (y * y));

    if (dist >= MAX_DISTANCE || dist == 0)
        return;

    sf::Vertex vertex[2];
    vertex[0].position = a;
    vertex[1].position = b;
    const auto alpha = sf::Uint8 ((dist < DISTANCE_OPA) ? 255 : 255 * (1 - (dist - DISTANCE_OPA)/(MAX_DISTANCE - DISTANCE_OPA)));
    vertex[0].color = vertex[1].color = sf::Color(255,255,255,alpha);
    window->draw(vertex, 2, sf::Lines);
}

void Points::setWindow(sf::RenderWindow &window) {
    this->window = &window;
}

Points::Points(unsigned int a, sf::RenderWindow &window){
    setWindow(window);
    list = new std::vector<Point>(a);
    list->shrink_to_fit();
}

