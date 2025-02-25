#include "ball.h"
#include <raylib.h>

extern int player_score;
extern int cpu_score;

void Ball::draw(){
    DrawCircle(x, y, radius, WHITE);
}

void Ball::Update(){
    x += speedX;
    y += speedY;

    if( y  - radius <= 0 || y + radius >= GetScreenHeight()){
        speedY *= -1;
    }
    
    if(x + radius >= GetScreenWidth()){
        player_score++;
        ResetBall();
    }
    if(x - radius <= 0){
        cpu_score++;
        ResetBall();
    }
}

void Ball::ResetBall(){
    x = GetScreenWidth() / 2;
    y = GetScreenHeight() / 2;

    int speed_choices[2] = {-1, 1};
    speedX *= speed_choices[GetRandomValue(0,1)];
    speedY *= speed_choices[GetRandomValue(0,1)];
}