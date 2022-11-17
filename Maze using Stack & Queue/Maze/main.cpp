/*test case 모두 통과했습니다.*/
#include <stdio.h>
#include "stack.h"
#include "pos.h"

#define PATH 1 // 지나갈 수 있는 위치
#define WALL 0 // 지나갈 수 없는 위치
#define VISITED 2 // 이미 방문한 위치
#define BACKTRACKED 3 // 방문했다가 되돌아 나온 위치
int n;
int maze_arr[50][50];  // 미로 배열
int count_cells(Position cur, Stack s);

int main(void){
    /*DFS && STACK // BFS && QUEUE*/
    // n 받아옴 ==> n*n 미로
    // 시작점부터 주변 탐색 ==> UNVISITED이면 stack push ==> 해당 칸 visited로 전환
    // push 하면서 count ++

    int num;

    FILE* fp = fopen("input.txt", "r");
    fscanf(fp, "%d", &num); // 총 test case 개수
    for(int t = 0; t < num; t++)
    {
        fscanf(fp, "%d", &n); // 총 몇칸
        for (int i = 0; i < n; i++){  // 배열에 file 데이타 넣기
            for (int j = 0; j < n; j++){
                fscanf(fp, "%d", &maze_arr[i][j]);
            }
        }
        Stack s = create();
        Position cur;
        cur.x = 0;
        cur.y = 0;
        
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                if(maze_arr[i][j] == 1){
                    cur.x = i;
                    cur.y = j;
                    printf("%d ", count_cells(cur, s));
                }
            }
        }
        printf("\n");
    }
    fclose(fp);
    return 0;
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

int count_cells(Position cur, Stack s)
{
    int count = 1;
    while(1)
    {
        maze_arr[cur.x][cur.y] = VISITED;
        bool forwarded = false;
        for (int dir = 0; dir < 8; dir++)
        {
            if (movable(cur, dir))
            {
                push(s, cur);
                count++;
                cur = move_to(cur, dir);
                forwarded = true;
                break;
            }
        }

        if (!forwarded) 
        {
            maze_arr[cur.x][cur.y] = BACKTRACKED;
            if (is_empty(s))
                return count;

            cur = peek(s);
            pop(s);    
        }
    } 
}
