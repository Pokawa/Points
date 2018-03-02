//
// Created by pokawa on 3/2/18.
//

#include "Point.h"
#include "config.h"

void Point::resetVector() {
    const double angle = (M_PI / 180) * (rand() % 360 - 180);
    this->vector.x = (float) sin(angle);
    this->vector.y = (float) cos(angle);
}

void Point::resetPosition() {
    const auto x = rand() % int(WIDTH * 0.6) + 0.2 * WIDTH;
    const auto y = rand() % int(HEIGHT * 0.6) + 0.2 * HEIGHT;
    this->setPosition(x, y);
}

void Point::move() {
    sf::Vector2f position = this->getPosition();
    position.x += this->vector.x * this->speed;
    position.y += this->vector.y * this->speed;
    this->setPosition(position);
}

Point::Point() : CircleShape(1) {
    this->resetVector();
    this->resetPosition();
    setFillColor(sf::Color::White);
}

void Point::wallBounce() {
    sf::Vector2f pos = this->getPosition();
    sf::Vector2f vec = this->vector;

    if (pos.x >= WIDTH && vec.x > 0)
        vec.x = -vec.x;

    if (pos.x <= 0 && vec.x < 0)
        vec.x = -vec.x;

    if (pos.y >= HEIGHT && vec.y > 0)
        vec.y = -vec.y;

    if (pos.y <= 0 && vec.y < 0)
        vec.y = -vec.y;

    this->vector = vec;
}

const double distance(const Point &a, const Point &b)
{
    sf::Vector2f aPos = a.getPosition();
    sf::Vector2f bPos = b.getPosition();
    return sqrt(pow(aPos.x - bPos.x, 2)+pow(aPos.y - bPos.y, 2));
}


