#ifndef BLOCK_HPP
#define BLOCK_HPP

#include "core.hpp"

struct Block : public Rectangle {
    bool destroyed {false};
    sf::Clock timer;
    int maxLives{1};
    int currentLives{1};
    float maxElapsedTime{5.f};
    Block(const float& x, const float& y);
    void update();
    void resize(const float& x, const float& y, const float& width = BLOCK_WIDTH, const float& height = BLOCK_HEIGHT);
};

#endif // !BRICK_HPP