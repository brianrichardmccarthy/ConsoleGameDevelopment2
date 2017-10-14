#ifndef BALL_HPP
#define BALL_HPP

#include <core.hpp>

/**
    Ball Struct
*/
struct Ball : public Circle {
    /**
        Velocity x, y speed.
        number of lives (for losing the game).
        active (for the level with multiple balls).
    */
    sf::Vector2f velocity{-BALL_VELOCITY, -BALL_VELOCITY};
    int lives{3};
    bool active{false};
    
    /**

        Ball constructor parameters x, y const reference. Creates new instance of Ball.
        Update parameters sf::Time (const reference). Updates Ball position, and some other stuff.
        Resize parameters window width, window height. Resizes the Ball to the new window width and height.

    */
    Ball(const float& x, const float& y);
    void update(const sf::Time& deltaTime);
    void resize(const float& width = WINDOW_WIDTH, const float& height= WINDOW_HEIGHT);
};

#endif // !BALL_HPP