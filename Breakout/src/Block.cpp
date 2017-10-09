#include "Block.hpp"

Block::Block(const float& x, const float& y) {
    resize(x, y);
}

void Block::resize(const float& x, const float& y, const float& width, const float& height) {
    shape.setPosition({x, y});
    shape.setSize({BLOCK_WIDTH, BLOCK_HEIGHT});
    shape.setFillColor(sf::Color::Green);
    shape.setOrigin({BLOCK_WIDTH/2, BLOCK_HEIGHT/2});
}