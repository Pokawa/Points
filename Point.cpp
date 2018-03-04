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
    const auto x = float(rand() % int(WIDTH * 0.6) + 0.2 * WIDTH);
    const auto y = float(rand() % int(HEIGHT * 0.6) + 0.2 * HEIGHT);
    setPosition(x, y);
}

void Point::move(const sf::Time & elapsed) {
    sf::Vector2f position = getPosition();
    const double speed = SPEED * (double)elapsed.asMilliseconds() / 1000;
    position.x += vector.x * speed;
    position.y += vector.y * speed;
    setPosition(position);
}

Point::Point() : CircleShape(1) {
    this->resetVector();
    this->resetPosition();
    setFillColor(sf::Color::White);
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



