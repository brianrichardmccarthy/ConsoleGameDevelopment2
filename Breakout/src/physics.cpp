#include "physics.hpp"

/**

    Function to get the dot product of a given vector

*/
auto sqr = [] (const sf::Vector2f& p) {
    return ((p.x*p.x)+(p.y*p.y));
};

void testCollision(const Paddle& paddle, Ball& ball) noexcept {
    
    // no collision happened, so do nothing else
    if (!isIntersecting(ball.shape, paddle.shape)) return;

    // else collision happen change the balls' x and y velocity
    ball.velocity.y = -BALL_VELOCITY;
    ball.velocity.x = (ball.x() < paddle.x()) ? -BALL_VELOCITY : BALL_VELOCITY;

}

void testCollision(Block& block, Ball& ball, int& score) noexcept {

    // no collision happened, so do nothing else
    if (!isIntersecting(ball.shape, block.shape)) return;
    
    // Only destroy the block, and increase the score if the ball is active
    if (ball.active) {
        block.destroyed = !(--block.currentLives);
        score += 5;
    }

    // calculate and change the ball velocity
    float overlapLeft{ball.right() - block.left()};
    float overlapRight{block.right() - ball.left()};
    float overlapTop{ball.bottom() - block.top()};
    float overlapBottom{block.bottom() - ball.top()};

    bool ballFromLeft{fabs(overlapLeft) < fabs(overlapRight)};
    bool ballFromTop{fabs(overlapTop) < fabs(overlapBottom)};

    float minOverlapX{ballFromLeft ? overlapLeft : overlapRight};
    float minOverlapY{ballFromTop ? overlapTop : overlapBottom};

    if (fabs(minOverlapX) < fabs(minOverlapY)) ball.velocity.x = ballFromLeft ? -BALL_VELOCITY : BALL_VELOCITY; 
    else ball.velocity.y = ballFromTop ? -BALL_VELOCITY : BALL_VELOCITY;
}

bool isIntersecting(const sf::CircleShape& circle, const sf::RectangleShape& rectangle) noexcept {
    
    // Calculate the x,y distance of the two shapes
    sf::Vector2f distance{fabsf(circle.getPosition().x - rectangle.getPosition().x), fabsf(circle.getPosition().y - rectangle.getPosition().y)};
    
    // if the ditance x or y is greater than the size of the rectangle plus the circle radius then it's not intersecting 
    if (distance.x > (rectangle.getSize().x + circle.getRadius())) return false;
    if (distance.y > (rectangle.getSize().y + circle.getRadius())) return false;

    // 
    if (distance.x <= (rectangle.getSize().x/2)) return true;
    if (distance.y <= (rectangle.getSize().y/2)) return true;

    // calculate the dot product of distance x minus half the rentangle x size and distance y minus half the rentangle y size 
    float disSqr = sqr({distance.x - rectangle.getSize().x/2, distance.y - rectangle.getSize().y/2});

    // return the distance squared is less than or equal to the circle radius squared
    return disSqr <= (circle.getRadius()*circle.getRadius());
}