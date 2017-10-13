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
    void init(int currentLevel = 1, const sf::Vector2u& size = sf::Vector2u{static_cast<unsigned int>(WINDOW_WIDTH), static_cast<unsigned int>(WINDOW_HEIGHT)});

    // game specific code
    sf::RenderWindow window;
    Paddle paddle;
    std::vector<Block> blocks;
    std::vector<Ball> balls;
    sf::Clock paddleTimer;
    int currentLevel{1};
    bool hasWon{false};
    bool isOver{false};
};
#endif