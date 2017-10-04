#include "Paddle.hpp"

Paddle::Paddle(const float& x, const float& y) {
    shape.setPosition({x, y});
    shape.setSize({PADDLE_WIDTH, PADDLE_HEIGHT});
    shape.setFillColor(sf::Color::Blue);
    shape.setOrigin({PADDLE_WIDTH/2, PADDLE_HEIGHT/2});
}

void Paddle::update(const sf::Time& deltaTime) {
    shape.move(velocity*deltaTime.asSeconds());
    
    if (left() < 0) shape.move(-left(), 0);
    if (right() > WINDOW_WIDTH) shape.move(-right() + WINDOW_WIDTH, 0); 
}