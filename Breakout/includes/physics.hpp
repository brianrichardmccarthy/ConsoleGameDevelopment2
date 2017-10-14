#ifndef PHYSICS_HPP
#define PHYSICS_HPP

#include "Paddle.hpp"
#include "Ball.hpp"
#include "Block.hpp"
#include <cmath>

/**

	I removed the templated version of isIntersecting for two reasons:
		1) When doing circle to block collision the function was large and I only put one or two line functions in header files.
		2) I don't think there was any need for the templated functions as the ball is the only object that collides with either the block or paddle.

	isIntersecting function takes in a circle shape and rectangle shape and if they overlap (using circle to block collision) returns true else false. 
	There is a bug of the ball not quite overlapping with the block or paddle in some cases.

	testCollision is overloaded for the ball to block collision, and the ball to to paddle collision. 
		If the ball collides with the paddle it bounces the ball back up.
		If the ball collides with a block increase the score, change ball direction, and take away the blocks' live. 

*/
bool isIntersecting(const sf::CircleShape& circle, const sf::RectangleShape& rectangle) noexcept;
void testCollision(const Paddle& paddle, Ball& ball) noexcept;
void testCollision(Block& block, Ball& ball, int& score) noexcept;

#endif // !PHYSICS_HPP