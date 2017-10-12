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
    // void init(int currentLevel, const sf::Vector2u& size = sf::Vector2u{static_cast<unsigned int>(WINDOW_WIDTH), static_cast<unsigned int>(WINDOW_HEIGHT)});

    sf::RenderWindow window;

    // game specific code
    Paddle paddle;
    std::vector<Block> blocks;
    std::vector<Ball> balls;
};
#endif