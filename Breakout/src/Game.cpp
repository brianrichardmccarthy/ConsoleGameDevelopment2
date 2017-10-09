#include <iostream>

#include "Game.hpp"
#include "physics.hpp"
#include <SFML/OpenGL.hpp>

Game::Game() :
    window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT),"Breakout"), ball(WINDOW_WIDTH/2, WINDOW_HEIGHT/2), paddle(WINDOW_WIDTH/2, WINDOW_HEIGHT-50) {
    
    window.setFramerateLimit(60);
    
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
            // (T& shape, const sf::Vector2f& newSize, const float& widthRatio, const float& heightRatio)
            // onResize(paddle.shape, {event.size.width, event.size.height}, PADDLE_RATIO_WIDTH, PADDLE_RATIO_HEIGHT);
            paddle.resize(paddle.shape.getPosition().x, paddle.shape.getPosition().y, event.size.width * PADDLE_RATIO_WIDTH, event.size.height * PADDLE_RATIO_HEIGHT);
            ball.resize(ball.shape.getPosition().x, ball.shape.getPosition().y, event.size.width * BALL_RATIO_RADIUS);
            for (auto& block : blocks)
                block.resize(block.shape.getPosition().x, block.shape.getPosition().y, event.size.width * BLOCK_RATIO_WIDTH, event.size.height * BLOCK_RATIO_HEIGHT);
            
            // (c+1)*(BLOCK_WIDTH+3) +22, (r+2) * (BLOCK_HEIGHT+5)
        }

    }
    
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape)) return false;
    
    // game specific code
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left)) paddle.velocity.x = -PADDLE_VELOCITY;
    else paddle.velocity.x =  (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right)) ? PADDLE_VELOCITY : 0;

    return true;
}

void Game::update(const sf::Time& deltaTime) {
    
    // game specific code
    ball.update(deltaTime);
    paddle.update(deltaTime);

    testCollision(paddle, ball);

    for (auto& block : blocks) testCollision(block, ball);
    
    blocks.erase(std::remove_if(blocks.begin(), blocks.end(), [] (const Block& block) {
        return block.destroyed;
    }), blocks.end());
}

void Game::render() {
    
    window.clear(sf::Color::Black);
    
    // game specific code

    window.draw(ball.shape);
    window.draw(paddle.shape);
    for (const auto& block : blocks) window.draw(block.shape);

    window.display();
}


