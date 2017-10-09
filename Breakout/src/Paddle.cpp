#include "Paddle.hpp"

Paddle::Paddle(const float& x, const float& y) {
    resize(x, y);
}

void Paddle::update(const sf::Time& deltaTime) {
    shape.move(velocity*deltaTime.asSeconds());
    
    if (left() < 0) shape.move(-left(), 0);
    if (right() > WINDOW_WIDTH) shape.move(-right() + WINDOW_WIDTH, 0); 
}

void Paddle::resize(const float& x, const float& y, const float& width, const float& height) {
    shape.setPosition({x, y});
    shape.setSize({width, height});
    shape.setFillColor(sf::Color::Blue);
    shape.setOrigin({width/2, height/2});
}