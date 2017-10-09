#ifndef GAME_HPP
#define GAME_HPP

#include <vector>

#include "Ball.hpp"
#include "Paddle.hpp"
#include "Block.hpp"
#include <iostream>

/*
template<class T>
auto onResize = [] (T& shape, const sf::Vector2f& newSize, const float& widthRatio, const float& heightRatio) {
    shape.setSize({newSize.x * widthRatio, newSize.y * heightRatio});
};
*/

class Game {
public:
    Game(const Game&) = delete;
    Game& operator=(const Game&) = delete;
    
    Game();
    void run();
    
private:
    bool processEvents();
    void update(const sf::Time& deltaTime);
    void render();
    void init(const float& windowWidth, const float& windowHeight, const float& blockWidth, const float& blockHeight);

    sf::RenderWindow window;

    // game specific code
    Ball ball;
    Paddle paddle;
    std::vector<Block> blocks;
    sf::Vector2i curSize{WINDOW_WIDTH, WINDOW_HEIGHT};
};
#endif