/*test case 모두 통과완료하였습니다.*/
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#define MAX 10
int cnt = 0;
int arr[MAX][MAX];
int N = 0; // 가로 세로 길이

void DFS(int x, int y, int n);
void read_file(FILE* fp); //file을 읽어옴

int main(void) {

	FILE* fp = fopen("C:/Users/PKNU/Desktop/maze.txt", "r"); // txt 파일을 바탕화면에 만들어 코드 테스트 진행하였습니다.
	read_file(fp);
	
	DFS(0, 0, N);
	printf("%d\n", cnt);
	return 0;
}
// 격자 좌표 범위
void DFS(int x, int y, int n)
{
	if (x >= n || y >= n || x < 0 || y < 0 || arr[x][y] != 0) //격자범위 벗어나는 경우
	{
		return;
	}
	else if (x == n - 1 && y == n - 1) // 도착지점 도달한 경우
	{
		cnt++;
		return;
	}
	else
	{
		arr[x][y] = 2; //지나온 길 1로 변경하여 탐색 방향 겹치지 않도록 함
		
		DFS(x, y + 1, n); // 동
		DFS(x + 1, y, n); // 남
		DFS(x, y - 1, n); // 서
		arr[x][y] = 0; // 앞의 길 다 탐색 후 다시 0으로 변경하여 다른 경우의 수에 반영이 되지 않도록 함
	}
}

void read_file(FILE *fp) {

	fscanf(fp, "%d ", &N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			fscanf(fp, "%d ", &arr[i][j]);
		}
	}
}