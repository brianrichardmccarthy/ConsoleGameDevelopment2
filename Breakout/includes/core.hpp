#ifndef CORE_H
#define CORE_H

#include <SFML/Graphics.hpp>

/**
    Const expression for the window, ball, paddle, and block height, width and size ratio for the default 800x600 window size for rescaling.
*/
constexpr int WINDOW_WIDTH{800}, WINDOW_HEIGHT{600};
constexpr float BALL_RADIUS{10.0f}, BALL_VELOCITY{200.0f};
constexpr float BALL_RATIO_RADIUS{BALL_RADIUS/WINDOW_WIDTH};
constexpr float PADDLE_WIDTH{120.0f}, PADDLE_HEIGHT{20.0f};
constexpr float PADDLE_RATIO_WIDTH{PADDLE_WIDTH / WINDOW_WIDTH}, PADDLE_RATIO_HEIGHT{PADDLE_HEIGHT / WINDOW_HEIGHT};
constexpr float PADDLE_VELOCITY{200.0f};
constexpr float BLOCK_WIDTH{60}, BLOCK_HEIGHT{20.0f};
constexpr float BLOCK_RATIO_WIDTH{BLOCK_WIDTH / WINDOW_WIDTH}, BLOCK_RATIO_HEIGHT{BLOCK_HEIGHT / WINDOW_HEIGHT};
constexpr int BLOCK_COLUMNS{11}, BLOCK_ROWS{4};

/**
    Base struct for ball 
*/
struct Circle {
    /**
        Shape is the ball to be drawn on the screen,
        Window size is the current size of the window used for rescaling the ball shape when the window size is changed.
        Position ratio is the percentage of the position in the window using default (800x600) and is used to place the ball in the same relative position when the window is rescaled.
    */
    sf::CircleShape shape;
    sf::Vector2u windowSize;
    sf::Vector2f positionRatio;
    
    /**
        X() returns the shapes' x position,
        Y() returns the shapes' y position,
        Left() returns the shapes' left position,
        Right() returns the shapes' right position,
        Top() returns the shapes' Top position,
        Bottom() returns the shapes' bottom position,
    */
    float x() const noexcept { return shape.getPosition().x; }
    float y() const noexcept { return shape.getPosition().y; }
    float left() const noexcept { return x() - shape.getRadius(); }
    float right() const noexcept { return x() + shape.getRadius(); }
    float top() const noexcept { return y() - shape.getRadius(); }
    float bottom() const noexcept { return y() + shape.getRadius(); }
};

/**
*/
struct Rectangle {
    /**
        Shape is the block or paddle to be drawn on the screen,
        Window size is the current size of the window used for rescaling the block or paddle shape when the window size is changed.
        Position ratio is the percentage of the position in the window using default (800x600) and is used to place the block or paddle in the same relative position when the window is rescaled.
    */
    sf::RectangleShape shape;
    sf::Vector2u windowSize;
    sf::Vector2f positionRatio;
    
    /**
        X() returns the shapes' x position,
        Y() returns the shapes' y position,
        Left() returns the shapes' left position,
        Right() returns the shapes' right position,
        Top() returns the shapes' Top position,
        Bottom() returns the shapes' bottom position,
    */
    float x() const noexcept { return shape.getPosition().x; }
    float y() const noexcept { return shape.getPosition().y; }
    float left() const noexcept { return x() - shape.getSize().x / 2.5f; }
    float right() const noexcept { return x() + shape.getSize().x / 2.5f; }
    float top() const noexcept { return y() - shape.getSize().y / 2.5f; }
    float bottom() const noexcept { return y() + shape.getSize().x / 2.5f; }
};

#endif

