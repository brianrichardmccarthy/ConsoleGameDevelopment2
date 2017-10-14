#ifndef GAME_HPP
#define GAME_HPP

#include <vector>

#include "Ball.hpp"
#include "Paddle.hpp"
#include "Block.hpp"
#include <iostream>

/**

    Game Class

*/
class Game {
public:
    /**

        Delete copy and assignment constructor.
        Default constructor is only avaliable constructor.
        Run proccess input, updates objects, and drawing objects.

    */
    Game(const Game&) = delete;
    Game& operator=(const Game&) = delete;
    Game();
    void run();
    
private:

    /**
        ProcessEvents handles input.
        Update gets each object to update itself.
        Initializes the level
    */
    bool processEvents();
    void update(const sf::Time& deltaTime);
    void render();
    void init(int currentLevel = 1, const sf::Vector2u& size = sf::Vector2u{static_cast<unsigned int>(WINDOW_WIDTH), static_cast<unsigned int>(WINDOW_HEIGHT)});

    // game specific code
    
    /**
        Render window to draw the objects,
        Paddle used by the player or automatic,
        Vector of blocks,
        Vector of balls,
        timer for paddle, and level,
        the current level (1, 2, 3, 4),
        is the game over and has the player won,
        the player score,
        the elapsed time (used in the level timer).
    */
    sf::RenderWindow window;
    Paddle paddle;
    std::vector<Block> blocks;
    std::vector<Ball> balls;
    sf::Clock paddleTimer;
    sf::Clock levelTimer;
    int currentLevel{1};
    bool hasWon{false};
    bool isOver{false};
    int score{0};
    float totalElapsedTime{0.f};
};
#endif