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


