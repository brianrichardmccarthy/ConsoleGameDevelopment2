#include "physics.hpp"

#include <cmath>

void testCollision(const Paddle& paddle, Ball& ball) noexcept {
    if (!isIntersecting(paddle, ball)) return;

    ball.velocity.y = -BALL_VELOCITY;
    ball.velocity.x = (ball.x() < paddle.x()) ? -BALL_VELOCITY : BALL_VELOCITY;

}

void testCollision(Block& block, Ball& ball) noexcept {

    if (!isIntersecting(block, ball)) return;
    block.destroyed = true;// !(--block.lives);

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