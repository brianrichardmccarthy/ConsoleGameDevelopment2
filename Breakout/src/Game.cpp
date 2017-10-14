#include <iostream>
#include "Game.hpp"
#include "physics.hpp"
#include <SFML/OpenGL.hpp>
#include <cstdlib>
#include <ctime>
#include <SFML/Graphics.hpp>

// Maximum time limit for one of the levels
constexpr float TIME_LIMIT{180.f};

/**
    Get random int less the the paramter referenced in
*/
auto randomInt = [] (const auto& max) {
    return (rand() % max);
};

/**
    Get Random bool
*/
auto randomBool = [] () {
    return (randomInt(2));
};

Game::Game() :
    window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT),"Blockout"), paddle(WINDOW_WIDTH/2, WINDOW_HEIGHT-50) {
    window.setFramerateLimit(60);

    // seed rand
    srand(static_cast<unsigned int>(time(0)));
    
    // init the first level
    init();
}

void Game::init(int currentLevel, const sf::Vector2u& size) {

    // clear out any balls in the vector
    if (balls.size()) balls.clear();

    // place main ball in vector
    balls.emplace_back(Ball((float) size.x/2, (float) size.y/2));
    
    // make sure ball is ative
    balls[0].active = true;

    // make a new paddle relative to the give size
    paddle = Paddle((float) size.x/2, (float) size.y-50);

    // create the blocks
    for (int c{0}; c < BLOCK_COLUMNS; ++c)
        for (int r{0}; r < BLOCK_ROWS; ++r)
            blocks.emplace_back((c+1)*(BLOCK_WIDTH+3) +22, (r+2) * (BLOCK_HEIGHT+5));
    
    // setup level specific stuff
    switch (currentLevel) {

        // do nothing for level one
        case 1: break;

        // add extra balls for level two
        case 2: {
                for (int r{randomBool() ? 1 : 2}, ballSpawned{currentLevel}, c{randomInt(BLOCK_COLUMNS)}; r < BLOCK_ROWS; ++r)
                        if (ballSpawned) {
                            blocks.erase(blocks.begin() + (r*c));
                            balls.emplace_back(Ball((c+1)*(BLOCK_WIDTH+3) +22, (r+2) * (BLOCK_HEIGHT+5)));
                            ballSpawned--;
                        } else return;
                break;
            }

        // level three add extra lives for all the blocks
        case 3: {
                for (auto& block : blocks) {
                    block.maxLives = 3;
                    block.currentLives = 3;
                }
            }
        // restart level clock for level four
        case 4: {
                levelTimer.restart();
                break;
            }
        default:
            break;
    }
    // reset current level
    this->currentLevel = currentLevel;
}

void Game::run() {
    // clock used to update objects
    sf::Clock clock;
    
    // while the window is open and is not over
    while (window.isOpen() && !isOver) {

        // get user input
        // if the user closes the window break out of the loop
        if (!processEvents()) break;

        // update each game object
        update(clock.restart());

        // render the objects
        render();
    }

    // couldn't get visual studio to load the font, so for now output the console
    std::cout << "Game over\n" << ((hasWon) ? "Congradualations I suppose." : "Haha, Sucker!") << std::endl;
    std::cout << ((hasWon) ? "But you only scored " + std::to_string(score) + " can you do better?" : "Not only can you not beat a simple game but you also got a crap score of " + std::to_string(score))  << std::endl;
}


bool Game::processEvents() {
    
    sf::Event event;
    while(window.pollEvent(event)) {

        // player closed the window
        if(event.type == sf::Event::Closed) {
            window.close();
            break;
        }

        // person resized the window
        if (event.type == sf::Event::Resized) {
            
            // change the view of the window
            window.setView(sf::View(sf::FloatRect(0.f,0.f, (float) event.size.width, (float) event.size.height)));
            
            // resize the paddle
            paddle.resize((float) event.size.width, (float) event.size.height);
            

            // for all balls resize them
            for (auto& ball : balls) ball.resize((float) event.size.width, (float) event.size.height);
            
            // for all blocks resize them
            for (auto& block : blocks) block.resize((float) event.size.width, (float) event.size.height);
        }

    }
    
    // player pressed the esc button
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape)) return false;
    
    // game specific code
    
    // the player set the paddle to/ from automatic
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) {
        if (paddleTimer.getElapsedTime().asSeconds() > .5f) { // must wait half a second to change paddle mode
            paddle.automatic = !paddle.automatic; // switch paddle is automatic
            paddle.velocity.x = (randomBool()) ? PADDLE_VELOCITY : -PADDLE_VELOCITY; // set the velocity
            paddleTimer.restart(); // restart the timer to change it again
        } 
    }
    
    // the player is controlling the paddle
    if (!paddle.automatic)
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left)) paddle.velocity.x = -PADDLE_VELOCITY; // move it left
        else paddle.velocity.x =  (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right)) ? PADDLE_VELOCITY : 0; // move it right or not at all
    
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Num1)) init(1, window.getSize()); // level from lecture notes
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Num2)) init(2, window.getSize()); // trapped balls
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Num3)) init(3, window.getSize()); // blocks have multiple lives that regenerate over time
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Num4)) init(4, window.getSize()); // must destroy all blocks before time runs out

    return true;
}

void Game::update(const sf::Time& deltaTime) {
    
    // End game checking
    // check if all blocks are destoryed
    if (!blocks.size())
        if (currentLevel == 4) hasWon = isOver = true; // last level, game is over, player has won
        else init(++currentLevel, {window.getSize().x, window.getSize().y}); // else load the next leve
    else if (!(balls.front().lives)) isOver = true; // or if the ball has no more lives the game is over and the player lost

    // if the current level is the time limit
    // check that the game is still less than the limit
    if (currentLevel == 4) {
        totalElapsedTime += levelTimer.getElapsedTime().asSeconds();
        if (totalElapsedTime > TIME_LIMIT) isOver = true;
    }

    // don't bother updating the level if the game is over
    if (isOver) return;

    // game specific code

    // update the paddle
    paddle.update(deltaTime);

    // update the balls
    for (auto& ball : balls) ball.update(deltaTime);
    
    // update the blocks for level with multiple lives
    if (blocks.front().maxLives > 1)
        for (auto& block : blocks) block.update();

    // test collisions for paddle and ball
    for (auto& ball : balls) 
        testCollision(paddle, ball);

    // test for collisions on the block and balls
    for (auto& ball : balls)
        for (auto& block : blocks) testCollision(block, ball, score);
    


    // remove dead blocks
    blocks.erase(std::remove_if(blocks.begin(), blocks.end(), [] (const Block& block) {
        return block.destroyed;
    }), blocks.end());
}

void Game::render() {
    
    // clear the window
    window.clear(sf::Color::Black);
    
    // game specific code

    // render all the balls
    for (const auto& ball : balls) window.draw(ball.shape);
    
    // render the paddle
    window.draw(paddle.shape);
    

    // render the blocks
    for (const auto& block : blocks) window.draw(block.shape);

    // display the window
    window.display();
}


