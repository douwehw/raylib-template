#include "ball.h"

Ball::Ball() 
{
    // Initialize position, velocity, radius, and bounces
    position = {100, 100};
    velocity = {5, 5};
    radius = 15;
    bounces = 0;
}

void Ball::Update() 
{
    // Update position based on velocity
    position.x += velocity.x;
    position.y += velocity.y;
    
    // Get screen dimensions
    int screen_width = GetScreenWidth();
    int screen_height = GetScreenHeight();
    
    // Check for collision with screen edges and bounce
    if (position.x + radius >= screen_width || position.x - radius <= 0) {
        velocity.x = -velocity.x;
        bounces++;
    }
    
    if (position.y + radius >= screen_height || position.y - radius <= 0) {
        velocity.y = -velocity.y;
        bounces++;
    }
}

void Ball::Draw() const
{
    // Draw the ball
    DrawCircle(position.x, position.y, radius, WHITE);
}