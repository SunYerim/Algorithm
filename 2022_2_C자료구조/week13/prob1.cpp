/*test case 모두 통과했습니다.*/
#include <stdlib.h>
#include <stdio.h>

int answer = 0;
bool check(int *graph, int row) {
	for (int i = row-1; i >= 0; i--) {
		//위의 행들이 세로로 있거나 대각에 있으면 return false
		if (graph[i] == graph[row]) {
			return false;
		}
		if (abs(graph[row] - graph[i]) == abs(row - i)) {
			return false;
		}
	}
	return true;
}


void backTracking(int *graph,int row, int n) {

	if (row == n) {
		answer++;
		return;
	}
	
	
	for (int col = 0; col < n; col++) {
		graph[row] = col;
		if (check(graph, row)) {
			backTracking(graph, row + 1, n);
		}
		graph[row] = 0;
	}
	
}

int main() {
	
    for (int n = 1; n <= 15; n++){
	    //동적 배열 생성
	    int *graph = (int*)malloc(sizeof(int) * n);

	    for (int i = 0; i < n; i++) {
		    graph[i] = 0;
	    }
	    backTracking(graph,0, n);
        
	    printf("%d: %d\n", n, answer);
        free(graph);
        answer = 0;
        
    }
	return 0;
}