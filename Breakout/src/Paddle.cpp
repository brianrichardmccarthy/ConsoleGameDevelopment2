#include "Paddle.hpp"

Paddle::Paddle(const float& x, const float& y) : automatic(false) {
    // windowSize = {static_cast<unsigned int>(WINDOW_WIDTH), static_cast<unsigned int>(WINDOW_HEIGHT)};
    windowSize = {static_cast<unsigned int>(WINDOW_WIDTH), static_cast<unsigned int>(WINDOW_HEIGHT)};
    
    // positionRatio = {x/WINDOW_WIDTH, y/WINDOW_HEIGHT};
    positionRatio = {x/WINDOW_WIDTH, y/WINDOW_HEIGHT};
    
    // shape.setPosition({x, y});
    shape.setPosition({x, y});
    
    // shape.setFillColor(sf::Color::Green);
    shape.setFillColor(sf::Color::Blue);
    
    // shape.setOrigin({BLOCK_WIDTH/2, BLOCK_HEIGHT/2});
    shape.setOrigin({PADDLE_WIDTH/2, PADDLE_HEIGHT/2});
    
    // shape.setSize({BLOCK_WIDTH, BLOCK_HEIGHT});
    shape.setSize({PADDLE_WIDTH, PADDLE_HEIGHT});
}

void Paddle::update(const sf::Time& deltaTime) {
    shape.move(velocity*deltaTime.asSeconds());
    
    if (!automatic) {
        if (left() < 0) shape.move(-left(), 0);
        if (right() > windowSize.x) shape.move(-right() + windowSize.x, 0);
    } else {
        if (left() < 0) velocity.x = PADDLE_VELOCITY;
        else if (right() > windowSize.x) velocity.x = -PADDLE_VELOCITY;
    }
}

void Paddle::resize(const float& x, const float& y, const float& width, const float& height) {
    windowSize = {static_cast<unsigned int>(width), static_cast<unsigned int>(height)};
    shape.setPosition({width * positionRatio.x, height * positionRatio.y});
    shape.setSize({width * PADDLE_RATIO_WIDTH, height * PADDLE_RATIO_HEIGHT});
    shape.setOrigin({(width * PADDLE_RATIO_WIDTH)/2, (height * PADDLE_RATIO_HEIGHT)/2});
    shape.setFillColor(sf::Color::Blue);
}