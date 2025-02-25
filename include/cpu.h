#ifndef CPU_H
#define CPU_H

#include "paddle.h"

class CpuPaddle : public Paddle {
public:
    void Update(int ballY);
};

#endif 
