//
// Created by pokawa on 3/2/18.
//

#include "Point.h"
#include "config.h"

void Point::resetVector() {
    const double angle = (M_PI / 180) * (rand() % 360 - 180);
    vector.x = (float) sin(angle);
    vector.y = (float) cos(angle);
}

void Point::resetPosition() {
    const auto x = float(rand() % WIDTH);
    const auto y = float(rand() % WIDTH);
    setPosition(x, y);
}

void Point::update(const sf::Time & elapsed) {
    const double speed = SPEED * (double)elapsed.asMilliseconds() / 1000;
    if (distance > 0)
        distance -= move(runVector, speed * 5);
    else
        move(vector, speed);
}

Point::Point() : CircleShape(1) {
    resetVector();
    resetPosition();
    setFillColor(sf::Color::White);
    distance = 0;
}

void Point::wallBounce() {
    sf::Vector2f pos = getPosition();

    if (pos.x >= WIDTH && vector.x > 0)
        vector.x = -vector.x;

    if (pos.x <= 0 && vector.x < 0)
        vector.x = -vector.x;

    if (pos.y >= HEIGHT && vector.y > 0)
        vector.y = -vector.y;

    if (pos.y <= 0 && vector.y < 0)
        vector.y = -vector.y;
}

void Point::setRun(const sf::Vector2f &vector, const double &distance) {
    this->distance = distance;
    this->runVector = vector;
}

const double Point::move(const sf::Vector2f &vector, const double &speed)
{
    sf::Vector2f position = getPosition();
    const double x = vector.x * speed;
    const double y = vector.y * speed;
    position.x += x;
    position.y += y;
    setPosition(position);
    return sqrt(x * x + y * y);
}



