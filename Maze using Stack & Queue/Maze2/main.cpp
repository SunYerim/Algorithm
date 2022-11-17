#include <stdio.h>
#include "queue.h"
#include "pos.h"

#define PATH 1 // 지나갈 수 있는 위치
#define WALL 0 // 지나갈 수 없는 위치
#define VISITED 2 // 이미 방문한 위치

int n;
int maze_arr[50][50];  // 미로 배열
int count_cells(Position cur, Queue s);

int main(void){
    int num;
    FILE *fp = fopen("input.txt", "r");
    fscanf(fp, "%d", &num);
    for (int i = 0; i < num; i++)
    {
        fscanf(fp, "%d", &n); // 총 가로세로 
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                fscanf(fp, "%d", &maze_arr[i][j]);
            }
        }

        Queue q = create();
        Position cur;

        cur.x = 0;
        cur.y = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (maze_arr[i][j] == 1){
                    cur.x = i;
                    cur.y = j;
                    printf("%d ", count_cells(cur, q));
                }
            }
        }   
        printf("\n");
    }
}

bool movable(Position cur, int dir){
    /*배열 안에 있고 1 ==> movable*/
    Position next = move_to(cur, dir); // 다음 좌표
    if (((next.x >= 0 && next.x < n ) && (next.y >= 0 && next.y < n )) && (maze_arr[next.x][next.y] == PATH)){
        return true;
    }
    else
        return false;    
}


int count_cells(Position cur, Queue q)
{   
    enqueue(q, cur);
    maze_arr[cur.x][cur.y] = VISITED;
    int count = 1;
    while(!is_empty(q))
    {
        cur = dequeue(q);
        for (int dir = 0; dir < 8; dir++)
        {
            if (movable(cur, dir))
            {
                Position p = move_to(cur, dir);
                maze_arr[p.x][p.y] = VISITED;
                count++;
                enqueue(q, p);
            }
        }
    }
    return count;
}