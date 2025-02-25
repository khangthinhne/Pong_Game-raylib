#include <raylib.h>
#include "paddle.h"

void Paddle::LimitMovement(){
    if(y <= 0){
        y = 0;
    }

    if(y + height >= GetScreenHeight()){
        y = GetScreenHeight() - height;
    }
}

void Paddle::draw(){
    DrawRectangleRounded(Rectangle{x, y, width, height}, 0.8, 0, WHITE );
}

void Paddle::Update(){
    if(IsKeyDown(KEY_LEFT_SHIFT)){
        speed = 15;
    }
    else speed = 7;
    if(IsKeyDown(KEY_UP)){
        y -= speed;
    }

    if(IsKeyDown(KEY_DOWN)){
        y += speed;
    }

    LimitMovement();
}
