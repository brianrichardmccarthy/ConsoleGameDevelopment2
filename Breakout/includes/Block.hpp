#ifndef BLOCK_HPP
#define BLOCK_HPP

#include "core.hpp"

struct Block : public Rectangle {
    bool destroyed {false};
    int lives{3};
    Block(const float& x, const float& y);
};

#endif // !BRICK_HPP