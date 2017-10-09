#ifndef BLOCK_HPP
#define BLOCK_HPP

#include "core.hpp"

struct Block : public Rectangle {
    bool destroyed {false};
    int lives{3};
    Block(const float& x, const float& y);
    void resize(const float& x, const float& y, const float& width = BLOCK_WIDTH, const float& height = BLOCK_HEIGHT);
};

#endif // !BRICK_HPP