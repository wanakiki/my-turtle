#ifndef TURTLE_H
#define TURTLE_H
#include <vector>

class turtle
{
private:
    int pos_x, pos_y;
    int direction;

public:
    turtle();

    // 按照目前的方向移动海龟指定距离并更新坐标
    void move(int distance);

    // 查询当前海龟位置
    std::vector<int> getPos();

    // 改变方向，左加1右减1
    void changeDirection(int v);
};

#endif // TURTLE_H
