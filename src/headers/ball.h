#pragma once

#include "raylib.h"

class Ball
{
public:
    Ball();
    void Update();
    void Draw() const;
    int Bounces() const { return bounces; }

private:
    Vector2 position;
    Vector2 velocity;
    float radius;
    int bounces;
};