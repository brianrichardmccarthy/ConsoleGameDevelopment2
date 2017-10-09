#include "Paddle.hpp"

Paddle::Paddle(const float& x, const float& y) : automatic(false) {
    resize(x, y);
}

void Paddle::update(const sf::Time& deltaTime) {
    shape.move(velocity*deltaTime.asSeconds());
    
    if (!automatic) {
        if (left() < 0) shape.move(-left(), 0);
        if (right() > WINDOW_WIDTH) shape.move(-right() + WINDOW_WIDTH, 0);
    } else {
        if (left() < 0) velocity.x = PADDLE_VELOCITY;
        else if (right() > WINDOW_WIDTH) velocity.x = -PADDLE_VELOCITY;
    }
}

void Paddle::resize(const float& x, const float& y, const float& width, const float& height) {
    shape.setPosition({x, y});
    shape.setSize({width, height});
    shape.setFillColor(sf::Color::Blue);
    shape.setOrigin({width/2, height/2});
}