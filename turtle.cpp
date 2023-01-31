#include "turtle.h"

turtle::turtle()
{
    // 初始位置与方向
    pos_x = pos_y = 50;
    direction = 0;
}

void turtle::move(int distance){
    std::vector<std::vector<int> > directions = {{1, 0}, {0, -1}, {-1, 0}, {0, 1}};

    int index = direction;
    pos_x += distance * directions[index][0];
    pos_y += distance * directions[index][1];

    return ;
}


std::vector<int> turtle::getPos(){
    return {pos_x, pos_y};
}


void turtle::changeDirection(int v){
    direction = (direction + 4 + v) % 4;
}
