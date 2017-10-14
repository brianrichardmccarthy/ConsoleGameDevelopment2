#ifndef Paddle_HPP
#define Paddle_HPP

#include "core.hpp"

/**

	Paddle Struct

*/
struct Paddle : public Rectangle {
    
    /**

		Velocity speed x (paddle shape will never move in the y position)
		automatic (let the computer move the paddle)

    */
    sf::Vector2f velocity;
    bool automatic{false};
    
    /**

		Paddle constructor parameters x, y const reference. Creates new instance of Paddle.
		Update parameters sf::Time (const reference). Updates paddle position.
		Resize parameters window width, window height. Resizes the paddle to the new window width and height.

    */
    Paddle(const float& x, const float& y);
    void update(const sf::Time& deltaTime);
    void resize(const float& width = WINDOW_WIDTH, const float& height = WINDOW_HEIGHT);
};

#endif // !Paddle_HPP