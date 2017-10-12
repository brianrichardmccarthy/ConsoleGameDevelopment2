#include <iostream>

#include "Game.hpp"
#include "physics.hpp"
#include <SFML/OpenGL.hpp>
#include <cstdlib>
#include <ctime>
#include <SFML/Graphics.hpp>

auto randomBool = [] () {
    return (rand() % 2);
};

Game::Game() :
    window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT),"Breakout"), paddle(WINDOW_WIDTH/2, WINDOW_HEIGHT-50) {
    
    window.setFramerateLimit(60);
    
    balls.emplace_back(Ball(WINDOW_WIDTH/2, WINDOW_HEIGHT/2));
    balls[0].active = true;

    srand(static_cast<unsigned int>(time(0)));

    // if (currentLevel-1)
       // for (int x = currentLevel-1; x; x--) balls.emplace_back(Ball(WINDOW_WIDTH/2+(50*x), WINDOW_HEIGHT/2+(50*x)));

    for (int c{0}; c < BLOCK_COLUMNS; ++c)
        for (int r{0}; r < BLOCK_ROWS; ++r)
            blocks.emplace_back((c+1)*(BLOCK_WIDTH+3) +22, (r+2) * (BLOCK_HEIGHT+5));
}

void Game::run() {
    sf::Clock clock;
    
    while (window.isOpen()) {
        if (!processEvents()) break;
        update(clock.restart());
        render();
    }
}


bool Game::processEvents() {
    
    sf::Event event;
    while(window.pollEvent(event)) {
        if(event.type == sf::Event::Closed) {
            window.close();
            break;
        }

        if (event.type == sf::Event::Resized) {
            window.setView(sf::View(sf::FloatRect(0.f,0.f, (float) event.size.width, (float) event.size.height)));
            
            paddle.resize(paddle.shape.getPosition().x, paddle.shape.getPosition().y, (float) event.size.width, (float) event.size.height);
            
            for (auto& ball : balls) ball.resize(ball.shape.getPosition().x, ball.shape.getPosition().y, (float) event.size.width, (float) event.size.height);
            
            for (auto& block : blocks) block.resize(block.shape.getPosition().x, block.shape.getPosition().y, (float) event.size.width, (float) event.size.height);
        }

    }
    
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape)) return false;
    
    // game specific code
    
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) {
        paddle.automatic = !paddle.automatic;
        paddle.velocity.x = (randomBool()) ? PADDLE_VELOCITY : -PADDLE_VELOCITY;
    }
    
    if (!paddle.automatic) {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left)) paddle.velocity.x = -PADDLE_VELOCITY;
        else paddle.velocity.x =  (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right)) ? PADDLE_VELOCITY : 0;
    }

    return true;
}

void Game::update(const sf::Time& deltaTime) {
    
    // game specific code
    paddle.update(deltaTime);
    for (auto& ball : balls) 
        if (ball.active) ball.update(deltaTime);

    for (auto& ball : balls) 
        testCollision(paddle, ball);

    for (auto& ball : balls)
        if (!ball.active) continue;
        else for (auto& block : blocks) testCollision(block, ball);
    
    blocks.erase(std::remove_if(blocks.begin(), blocks.end(), [] (const Block& block) {
        return block.destroyed;
    }), blocks.end());
}

void Game::render() {
    
    window.clear(sf::Color::Black);
    
    // game specific code

    for (const auto& ball : balls) window.draw(ball.shape);
    
    window.draw(paddle.shape);
    
    for (const auto& block : blocks) window.draw(block.shape);

    window.display();
}


