#include <raylib.h>
#include "cpu.h"

void CpuPaddle::Update(int ballY){
    if(y + height / 2> ballY){
        y -= speed;
    }
    if(y + height / 2<= ballY){
        y += speed;
    }
        LimitMovement();
}
