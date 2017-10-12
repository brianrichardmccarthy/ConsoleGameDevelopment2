#ifndef PHYSICS_HPP
#define PHYSICS_HPP

#include "Paddle.hpp"
#include "Ball.hpp"
#include "Block.hpp"
#include <cmath>

/*
template<class T1, class T2>
bool isIntersecting(const T1& a, const T2& b) noexcept {
    
    sf::Vector2f distance{fabsf(a.shape.getPosition().x - b.shape.getPosition().x), fabsf(a.shape.getPosition().y - b.shape.getPosition().y)};
    
    if (
        (distance.x > (b.shape.getSize().x + a.shape.getRadius())) 
         || (distance.y > (b.shape.getSize().y + a.shape.getRadius()))) return false;

    if ((distance.x <= (b.getShape.getSize().x/2)) || (distance.y <= (b.getShape.getSize().y/2))) return true;

    float disSqr = sqr(distance.x - b.getShape.getSize().x/2) + sqr(distance.y - b.getShape.getSize().y/2);
    return disSqe <= (a.shape.getRadius()*a.shape.getRadius());
}
*/

bool isIntersecting(const sf::CircleShape& circle, const sf::RectangleShape& rectangle) noexcept;
void testCollision(const Paddle& paddle, Ball& ball) noexcept ;
void testCollision(Block& block, Ball& ball) noexcept ;
void testCollision(Block& block1, Block& block2);

#endif // !PHYSICS_HPP