#ifndef GAME_HPP
#define GAME_HPP

#include <vector>

#include "Ball.hpp"
#include "Paddle.hpp"
#include "Block.hpp"
#include <iostream>

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

    sf::RenderWindow window;

    // game specific code
    int currentLevel{3};
    Paddle paddle;
    std::vector<Block> blocks;
    std::vector<Ball> balls;
};
#endif