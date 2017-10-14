#include "Block.hpp"

Block::Block(const float& x, const float& y) {
    // set the position, size origin, and fill color
    shape.setPosition({x, y});
    shape.setSize({BLOCK_WIDTH, BLOCK_HEIGHT});
    shape.setOrigin({BLOCK_WIDTH/2, BLOCK_HEIGHT/2});
    shape.setFillColor(sf::Color::Green);

    // set the position ratio, and the current window size
    positionRatio = {x/WINDOW_WIDTH, y/WINDOW_HEIGHT};
    windowSize = {static_cast<unsigned int>(WINDOW_WIDTH), static_cast<unsigned int>(WINDOW_HEIGHT)};
}

void Block::update() {
    // don't update it the balls should only be hit once
    if (maxLives == 1) return;

    // If elapsed time is greater the max elapsed time
    if (timer.getElapsedTime().asSeconds() > maxElapsedTime) {
        // restart the clock
        timer.restart();

        // if the current lives is less than max lives add one to current lives
        if (currentLives < maxLives) currentLives++;
    }
    
    // change the color of the shape depending on its current level of lives
    // also change the elapsed time to recover health
    switch (currentLives) {
        case 1: {
                shape.setFillColor(sf::Color::Red);
                maxElapsedTime = {15.f};
                break;
            }
        case 2: {
                shape.setFillColor(sf::Color::Yellow);
                maxElapsedTime = {10.f};
                break;
            }
        case 3: {
                shape.setFillColor(sf::Color::Green);
                maxElapsedTime = {5.f};
                break;
            }
        default:
            break;
    }


}

void Block::resize(const float& width, const float& height) {
    // update the window size vector
    windowSize = {static_cast<unsigned int>(width), static_cast<unsigned int>(height)};
    
    // update the shape to the width of window times position ratio x, likewise for height and position ratio y
    shape.setPosition({width * positionRatio.x, height * positionRatio.y});

    // update the shape size relative to the new width, and height
    shape.setSize({width * BLOCK_RATIO_WIDTH, height * BLOCK_RATIO_HEIGHT});
    
    // update the origin to the centre of the shape
    shape.setOrigin({(width * BLOCK_RATIO_WIDTH)/2, (height * BLOCK_RATIO_HEIGHT)/2});
}