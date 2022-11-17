#include "pos.h"

int offset[8][2] = {
    {-1, 0}, // 북
    {-1, 1}, // 북동
    {0, 1}, // 동
    {1, 1}, // 동남
    {1, 0}, // 남
    {1, -1}, // 남서
    {0, -1}, // 서
    {-1, -1} // 북서
};

Position move_to(Position pos, int dir){
    Position next;
    next.x = pos.x + offset[dir][0];
    next.y = pos.y + offset[dir][1];
    return next;
}
