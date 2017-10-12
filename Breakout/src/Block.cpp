#include "Block.hpp"

Block::Block(const float& x, const float& y) {
    shape.setPosition({x, y});
    shape.setSize({BLOCK_WIDTH, BLOCK_HEIGHT});
    shape.setOrigin({BLOCK_WIDTH/2, BLOCK_HEIGHT/2});
    shape.setFillColor(sf::Color::Green);
    positionRatio = {x/WINDOW_WIDTH, y/WINDOW_HEIGHT};
    windowSize = {static_cast<unsigned int>(WINDOW_WIDTH), static_cast<unsigned int>(WINDOW_HEIGHT)};
}

void Block::resize(const float& x, const float& y, const float& width, const float& height) {
    windowSize = {static_cast<unsigned int>(width), static_cast<unsigned int>(height)};
    shape.setPosition({width * positionRatio.x, height * positionRatio.y});
    shape.setSize({width * BLOCK_RATIO_WIDTH, height * BLOCK_RATIO_HEIGHT});
    shape.setOrigin({(width * BLOCK_RATIO_WIDTH)/2, (height * BLOCK_RATIO_HEIGHT)/2});
}