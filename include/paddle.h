#pragma once

class Paddle
{
    protected:
    void LimitMovement();
    public:
    float width, height;
    float x, y;
    int speed;

    void draw();
    void Update();
};
