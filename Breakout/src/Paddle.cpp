#include "Paddle.hpp"

Paddle::Paddle(const float& x, const float& y) : automatic(false) {
    // set the position ratio, and the current window size
    windowSize = {static_cast<unsigned int>(WINDOW_WIDTH), static_cast<unsigned int>(WINDOW_HEIGHT)};
    positionRatio = {x/WINDOW_WIDTH, y/WINDOW_HEIGHT};

    // set the position, size origin, and fill color
    shape.setPosition({x, y});
    shape.setFillColor(sf::Color::Blue);
    shape.setOrigin({PADDLE_WIDTH/2, PADDLE_HEIGHT/2});
    shape.setSize({PADDLE_WIDTH, PADDLE_HEIGHT});
}

void Paddle::update(const sf::Time& deltaTime) {
    
    // move the paddle with Euler's method
    shape.move(velocity*deltaTime.asSeconds());
    
    if (!automatic) {
        // move the paddle to the right
        if (left() < 0) shape.move(-left(), 0);
        
        // move the paddle to the left
        if (right() > windowSize.x) shape.move(-right() + windowSize.x, 0);
    } else {
        // reverse the direction if bouncing off the the left or right
        if (left() < 0) velocity.x = PADDLE_VELOCITY;
        else if (right() > windowSize.x) velocity.x = -PADDLE_VELOCITY;
    }
}

void Paddle::resize(const float& width, const float& height) {

    // update the window size vector
    windowSize = {static_cast<unsigned int>(width), static_cast<unsigned int>(height)};
    shape.setPosition({width * positionRatio.x, height * positionRatio.y});

    // update the shape to the width of window times position ratio x, likewise for height and position ratio y
    shape.setSize({width * PADDLE_RATIO_WIDTH, height * PADDLE_RATIO_HEIGHT});

    // update the shape size relative to the new width, and height
    shape.setOrigin({(width * PADDLE_RATIO_WIDTH)/2, (height * PADDLE_RATIO_HEIGHT)/2});

    // update the origin to the centre of the shape
    shape.setFillColor(sf::Color::Blue);
}