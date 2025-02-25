#include <raylib.h>
#include "ball.h"

int player_score = 0;
int cpu_score = 0;

class Paddle
{
    protected:
    void LimitMovement(){
        if(y <= 0){
            y = 0;
        }

        if(y + height >= GetScreenHeight()){
            y = GetScreenHeight() - height;
        }
    }
    public:
    float width, height;
    float x, y;
    int speed;

    void draw(){
        DrawRectangleRounded(Rectangle{x, y, width, height}, 0.8, 0, WHITE );
    }

    void Update(){
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
};

class CpuPaddle: public Paddle
{
    public:

    void Update(int ballY){
        if(y + height / 2> ballY){
            y -= speed;
        }
        if(y + height / 2<= ballY){
            y += speed;
        }
         LimitMovement();
    }
};


int main(){
    //Initialize Window
    const int screenWidth = 1200;
    const int screenHeight = 800;
    InitWindow(screenWidth, screenHeight, "My Pong Game");
    SetTargetFPS(60);

    Color darkblue = {20, 120, 133,255};
    Color darkblue2 = {20, 120, 115, 255};
    Color DarkGreen = {255, 255, 255, 70};
    // Color pink = {252, 74, 146, 255};
    //Ball property
    Ball ball;
    ball.radius = 15;
    ball.speedX = 7;
    ball.speedY = 7;
    ball.x = screenWidth / 2;
    ball.y = screenHeight / 2;

    //Paddle
    Paddle paddle;
    paddle.x = 15;
    paddle.y = screenHeight / 2 - 50;
    paddle.width = 30;
    paddle.height = 100;
    paddle.speed = 7;


    //CPU Paddle inheritates from class paddle: atrributes, methods,..
    CpuPaddle cpu;
    cpu.width = 30;
    cpu.height = 100;
    cpu.x = screenWidth - cpu.width - 15;
    cpu.y = screenHeight / 2 - cpu.height / 2;
    cpu.speed = 7; 

    while(!WindowShouldClose()){
        //Event Handling
        BeginDrawing();
        ball.Update();
        paddle.Update();
        cpu.Update(ball.y);

        //Checking for collisions
        if(CheckCollisionCircleRec(Vector2{ball.x, ball.y},ball.radius, Rectangle{paddle.x, paddle.y, paddle.width, paddle.height})){
        
            ball.speedX *= -1;
        }
        if(CheckCollisionCircleRec(Vector2{ball.x, ball.y},ball.radius, Rectangle{cpu.x, cpu.y, cpu.width, cpu.height})){
        
            ball.speedX *= -1;
        }
        ClearBackground(darkblue);
        DrawRectangle(0,0,screenWidth / 2, screenHeight, darkblue2);
        DrawCircle(screenWidth / 2, screenHeight / 2, screenWidth / 5, DarkGreen);
        ball.draw();
        paddle.draw();
        cpu.draw();
        
        DrawText(TextFormat("%i", player_score), screenWidth / 4 - 20, 20, 80, WHITE);
        DrawText(TextFormat("%i", cpu_score), screenWidth / 4 * 3 - 20, 20, 80, WHITE);
        DrawLine(screenWidth / 2, 0, screenWidth / 2, screenHeight, WHITE);
        EndDrawing();
    }                                                   
    CloseWindow();
    return 0;
}