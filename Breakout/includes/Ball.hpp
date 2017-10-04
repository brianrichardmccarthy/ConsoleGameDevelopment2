#ifndef BALL_HPP
#define BALL_HPP

#include <core.hpp>

struct Ball : public Circle {
    sf::Vector2f velocity{-BALL_VELOCITY, -BALL_VELOCITY};
    Ball(const float& x, const float& y);
    void update(const sf::Time& deltaTime);
};

#endif // !BALL_HPP