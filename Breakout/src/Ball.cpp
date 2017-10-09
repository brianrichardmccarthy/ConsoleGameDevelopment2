#include "Ball.hpp"
#include <iostream>

Ball::Ball(const float& x, const float& y) : active(false) {
    resize(x, y);
}

void Ball::update(const sf::Time& deltaTime) {
    shape.move(velocity*(deltaTime.asSeconds()));

    velocity.x = (left() < 0) ? BALL_VELOCITY : (right() > WINDOW_WIDTH) ? -BALL_VELOCITY : velocity.x;
    velocity.y = (top() < 0) ? BALL_VELOCITY : (bottom() > WINDOW_HEIGHT) ? -BALL_VELOCITY : velocity.y;
}

void Ball::resize(const float& x, const float& y, const float& radius) {
    shape.setPosition({x, y});
    shape.setRadius(BALL_RADIUS);
    shape.setFillColor(sf::Color::Red);
    shape.setOrigin({BALL_RADIUS, BALL_RADIUS});
}