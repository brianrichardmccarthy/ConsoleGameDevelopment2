#include "Block.hpp"

Block::Block(const float& x, const float& y) {
    shape.setPosition({x, y});
    shape.setSize({BLOCK_WIDTH, BLOCK_HEIGHT});
    shape.setFillColor(sf::Color::Green);
    shape.setOrigin({BLOCK_WIDTH/2, BLOCK_HEIGHT/2});
}
