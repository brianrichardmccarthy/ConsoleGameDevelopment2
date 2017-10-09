#ifndef BALL_HPP
#define BALL_HPP

#include <core.hpp>

struct Ball : public Circle {
    sf::Vector2f velocity{-BALL_VELOCITY, -BALL_VELOCITY};
    Ball(const float& x, const float& y);
    void update(const sf::Time& deltaTime);
    void resize(const float& x, const float& y, const float& radius = BALL_RADIUS);
};

#endif // !BALL_HPP