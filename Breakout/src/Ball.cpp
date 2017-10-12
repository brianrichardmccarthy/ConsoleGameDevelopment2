#include "Ball.hpp"
#include <iostream>

Ball::Ball(const float& x, const float& y) : active(false) {
    positionRatio = {x/WINDOW_WIDTH, y/WINDOW_HEIGHT};
    windowSize = {static_cast<unsigned int>(WINDOW_WIDTH), static_cast<unsigned int>(WINDOW_HEIGHT)};
    shape.setPosition({x, y});
    shape.setRadius({BALL_RADIUS});
    shape.setOrigin({BALL_RADIUS, BALL_RADIUS});
    shape.setFillColor(sf::Color::Red);
}

void Ball::update(const sf::Time& deltaTime) {
    shape.move(velocity*(deltaTime.asSeconds()));

    if (!active && bottom() > (windowSize.y * .75f)) active = true;

    velocity.x = (left() < 0) ? BALL_VELOCITY : (right() > windowSize.x) ? -BALL_VELOCITY : velocity.x;
    velocity.y = (top() < 0) ? BALL_VELOCITY : (bottom() > windowSize.y) ? -BALL_VELOCITY : velocity.y;
}

void Ball::resize(const float& x, const float& y, const float& width, const float& height) {
    windowSize = {static_cast<unsigned int>(width), static_cast<unsigned int>(height)};
    shape.setPosition({width * positionRatio.x, height * positionRatio.y});
    shape.setRadius({width * BALL_RATIO_RADIUS});
    shape.setOrigin({(width * BALL_RATIO_RADIUS)/2, (height * BALL_RATIO_RADIUS)/2});
}