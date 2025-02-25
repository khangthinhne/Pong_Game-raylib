#pragma once

class Ball{
    public:
    float x, y;
    int speedX, speedY;
    int radius;
    
    void draw();
    void Update();
    void ResetBall();

};