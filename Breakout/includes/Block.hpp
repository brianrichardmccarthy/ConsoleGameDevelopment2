#ifndef BLOCK_HPP
#define BLOCK_HPP

#include "core.hpp"

/**

    Block Struct

*/
struct Block : public Rectangle {
    
    /**

        Parameters:
            destroyed (used for removing blocks).
            max lives how many times the block can be hit.
            current lives how many times has the block been hit.

    */
    bool destroyed {false};
    sf::Clock timer;
    int maxLives{1};
    int currentLives{1};
    float maxElapsedTime{5.f};
    
    /**

        Block constructor parameters x, y const reference. Creates new instance of Block.
        Update if the block should regenerate its health over time if not hit.
        Resize parameters window width, window height. Resizes the block to the new window width and height.

    */
    Block(const float& x, const float& y);
    void update();
    void resize(const float& width = BLOCK_WIDTH, const float& height = BLOCK_HEIGHT);
};

#endif // !BRICK_HPP