#include "physics.hpp"

auto sqr = [] (const sf::Vector2f& p) {
    return ((p.x*p.x)+(p.y*p.y));
};

void testCollision(const Paddle& paddle, Ball& ball) noexcept {
    if (!isIntersecting(ball.shape, paddle.shape)) return;

    ball.velocity.y = -BALL_VELOCITY;
    ball.velocity.x = (ball.x() < paddle.x()) ? -BALL_VELOCITY : BALL_VELOCITY;

}

void testCollision(Block& block, Ball& ball, int& score) noexcept {

    if (!isIntersecting(ball.shape, block.shape)) return;
    
    if (ball.active) block.destroyed = !(--block.currentLives);

    score += 5;

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
    
    sf::Vector2f distance{fabsf(circle.getPosition().x - rectangle.getPosition().x), fabsf(circle.getPosition().y - rectangle.getPosition().y)};
    
    if (distance.x > (rectangle.getSize().x + circle.getRadius())) return false;
    if (distance.y > (rectangle.getSize().y + circle.getRadius())) return false;

    if (distance.x <= (rectangle.getSize().x/2)) return true;
    if (distance.y <= (rectangle.getSize().y/2)) return true;

    float disSqr = sqr({distance.x - rectangle.getSize().x/2, distance.y - rectangle.getSize().y/2});
    return disSqr <= (circle.getRadius()*circle.getRadius());
}