#include "Ball.hpp"

Ball::Ball(const float& x, const float& y) : active(false) {

    // set the position ratio, and the current window size
    positionRatio = {x/WINDOW_WIDTH, y/WINDOW_HEIGHT};
    windowSize = {static_cast<unsigned int>(WINDOW_WIDTH), static_cast<unsigned int>(WINDOW_HEIGHT)};

    // set the position, size origin, and fill color
    shape.setPosition({x, y});
    shape.setRadius({BALL_RADIUS});
    shape.setOrigin({BALL_RADIUS, BALL_RADIUS});
    shape.setFillColor(sf::Color::Red);
}

void Ball::update(const sf::Time& deltaTime) {
    // move the ball using Euler's method
    shape.move(velocity*(deltaTime.asSeconds()));

    // if ball isn't active and it drops below a certain height activate it
    if (!active && bottom() > (windowSize.y * .75f)) active = true;

    // bounce the ball off the left and right of the window
    velocity.x = (left() < 0) ? BALL_VELOCITY : (right() > windowSize.x) ? -BALL_VELOCITY : velocity.x;
    
    // bounce the ball off the bottom and top of the window
    if ((bottom() > windowSize.y)) {
        lives--; // take a live away if the player misses the ball with the paddle
        velocity.y =-BALL_VELOCITY;
    } else velocity.y = (top() < 0) ? BALL_VELOCITY : velocity.y;
}

void Ball::resize(const float& width, const float& height) {
    // update the window size vector
    windowSize = {static_cast<unsigned int>(width), static_cast<unsigned int>(height)};
    
    // update the shape to the width of window times position ratio x, likewise for height and position ratio y
    shape.setPosition({width * positionRatio.x, height * positionRatio.y});
    
    // update the shape size relative to the new width, and height
    shape.setRadius({width * BALL_RATIO_RADIUS});

    // update the origin to the centre of the shape
    shape.setOrigin({(width * BALL_RATIO_RADIUS)/2, (height * BALL_RATIO_RADIUS)/2});
}