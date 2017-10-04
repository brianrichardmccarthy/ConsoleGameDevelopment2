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
    template<class T1>
    void resize(T1& shape, const int& x, const int& y) const {
        const sf::Vector2i scale {x/curSize.x, y/curSize.y};

        std::cout << "X= " << scale.x << ", Y= " << scale.y << std::endl;
    }
    
private:
    bool processEvents();
    void update(const sf::Time& deltaTime);
    void render();


    sf::RenderWindow window;

    // game specific code
    Ball ball;
    Paddle paddle;
    std::vector<Block> blocks;
    sf::Vector2i curSize{WINDOW_WIDTH, WINDOW_HEIGHT};

};
#endif