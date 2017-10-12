#include <iostream>

#include "Game.hpp"
#include "physics.hpp"
#include <SFML/OpenGL.hpp>
#include <cstdlib>
#include <ctime>
#include <SFML/Graphics.hpp>

auto randomInt = [] (const auto& max) {
    return (rand() % max);
};

auto randomBool = [] () {
    return (rand() % 2);
};

Game::Game() :
    window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT),"Breakout"), paddle(WINDOW_WIDTH/2, WINDOW_HEIGHT-50) {
    window.setFramerateLimit(60);
    srand(static_cast<unsigned int>(time(0)));
    init();
}

void Game::init(int currentLevel, const sf::Vector2u& size) {
    if (balls.size()) balls.clear();
    balls.emplace_back(Ball((float) size.x/2, (float) size.y/2));
    balls[0].active = true;
    paddle = Paddle((float) size.x/2, (float) size.y-50);

    for (int c{0}, ballSpawned{(currentLevel == 2) ? currentLevel: 0}; c < BLOCK_COLUMNS; ++c)
        for (int r{0}; r < BLOCK_ROWS; ++r)
            blocks.emplace_back((c+1)*(BLOCK_WIDTH+3) +22, (r+2) * (BLOCK_HEIGHT+5));
    switch (currentLevel) {
        case 2: {
                // trapped ball
                for (int r{randomInt(BLOCK_ROWS)}, ballSpawned{currentLevel}, c{randomInt(BLOCK_COLUMNS)}; r < BLOCK_ROWS; ++r)
                        if (ballSpawned) {
                            blocks.erase(blocks.begin() + (r*c));
                            balls.emplace_back(Ball((c+1)*(BLOCK_WIDTH+3) +22, (r+2) * (BLOCK_HEIGHT+5)));
                            ballSpawned--;
                        } else return;
                break;
            }
        case 3: {
                // must destroy all blocks before time runs out
                break;
            }
        case 4: {
                // blocks have multiple lives that regenerate over time
                for (auto& block : blocks) {
                    block.maxLives = 3;
                    block.currentLives = 3;
                }
            }
        case 5: {
                // Bonus and traps
                break;
            }
        case 6: {
                // Random Procedural Generation
                break;
            }
        default:
            break;
    }
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
        if (paddleTimer.getElapsedTime().asSeconds() > .5f) {
            paddle.automatic = !paddle.automatic;
            paddle.velocity.x = (randomBool()) ? PADDLE_VELOCITY : -PADDLE_VELOCITY;
            paddleTimer.restart();
        } 
    }
    
    if (!paddle.automatic)
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left)) paddle.velocity.x = -PADDLE_VELOCITY;
        else paddle.velocity.x =  (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right)) ? PADDLE_VELOCITY : 0;
    
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Num1)) init(1, window.getSize()); // level from lecture notes
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Num2)) init(2, window.getSize()); // trapped balls
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Num3)) init(3, window.getSize()); // must destroy all blocks before time runs out
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Num4)) init(4, window.getSize()); // blocks have multiple lives that regenerate over time
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Num5)) init(5, window.getSize()); // Bonus and traps
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Num6)) init(6, window.getSize()); // Random Procedural Generation

    return true;
}

void Game::update(const sf::Time& deltaTime) {
    
    // game specific code
    paddle.update(deltaTime);
    for (auto& ball : balls) ball.update(deltaTime);

    for (auto& ball : balls) 
        if (ball.active) testCollision(paddle, ball);

    for (auto& ball : balls)
        for (auto& block : blocks) testCollision(block, ball);
    
    if (blocks.size())
        if (blocks.front().maxLives > 1)
            for (auto& block : blocks) block.update();

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


