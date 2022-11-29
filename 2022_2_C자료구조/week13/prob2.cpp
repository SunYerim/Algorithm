/*test case 모두 통과했습니다.*/
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

int cnt = 0;
int arr[MAX][MAX];

void DFS(int x, int y, int n);

int main(void){
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            scanf("%d", &arr[i][j]);
        }
    }

    DFS(0, 0, n);

    printf("%d\n", cnt);
    return 0;
}

// (0,0) ~ (6,6) 격자 좌표 범위

void DFS(int x, int y, int n)
{
    if (x >= n || y >= n || x < 0 || y < 0 || arr[x][y] != 0) //격자범위 벗어나는 경우
    {
        return;
    }
    else if (x == n-1 && y == n-1) // 도착지점 도달한 경우
    {
        cnt++;
        return;
    }
    else
    {
        arr[x][y] = 2; //지나온 길 1로 변경하여 탐색 방향 겹치지 않도록 함

        DFS(x - 1, y, n); // 북
        DFS(x, y + 1, n); // 동
        DFS(x + 1, y, n); // 남
        DFS(x, y - 1, n); // 서
       
        arr[x][y] = 0; // 앞의 길 다 탐색 후 다시 0으로 변경하여 다른 경우의 수에 반영이 되지 않도록 함   
    }
}
