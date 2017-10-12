#ifndef BALL_HPP
#define BALL_HPP

#include <core.hpp>

struct Ball : public Circle {
    sf::Vector2f velocity{-BALL_VELOCITY, -BALL_VELOCITY};
    bool active{false};
    Ball(const float& x, const float& y);
    void update(const sf::Time& deltaTime);
    void resize(const float& x, const float& y, const float& width = WINDOW_WIDTH, const float& height= WINDOW_HEIGHT);
};

#endif // !BALL_HPP