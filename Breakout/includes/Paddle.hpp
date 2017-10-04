#ifndef Paddle_HPP
#define Paddle_HPP

#include "core.hpp"

struct Paddle : public Rectangle {
    sf::Vector2f velocity;
    Paddle(const float& x, const float& y);
    void update(const sf::Time& deltaTime);
};

#endif // !Paddle_HPP