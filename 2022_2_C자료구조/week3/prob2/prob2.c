//comment: test case 모두 통과하였습니다.
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define swap(a, b){ int t; t = a; a = b; b = t;}
void input_value(int** m, int row, int col);
void output_value(int** m, int row, int col);
void sorting_value(int** m, int row, int col);

int main(void) {

	int num, number;
	scanf("%d", &num);
	rewind(stdin);

	int** num_arr = malloc(sizeof(int*) * num); //이중포인터배열

	for (int i = 0; i < num; i++) {
		num_arr[i] = malloc(sizeof(int) * 2);
	}

	input_value(num_arr, num, 2);
	sorting_value(num_arr, num, 2);
	output_value(num_arr, num, 2);
	free(num_arr);

	return 0;
}

void input_value(int** m, int row, int col) {
	for (int i = 0; i < row; i++) {
		scanf("%d %d", &m[i][0], &m[i][1]);
		rewind(stdin);
	}
}

void sorting_value(int** m, int row, int col) {
	//시작점 크기 비교 --> 시작점 똑같은 것 끼리 크기 비교
	int max;
	int i, j;

	for (i = row; i > 1; i--) {
		max = 0;
		for (j = 1; j < i; j++) {
			if (m[max][0] < m[j][0]) {
				max = j;
			}
			else if (m[max][0] == m[j][0]) {
				if (m[max][1] < m[j][1]) {
					swap(m[max], m[j]);
				}
			}
		}
		swap(m[max], m[i - 1]);
		
	}
}

void output_value(int** m, int row, int col) {
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			printf("%d ", m[i][j]);
		}
		printf("\n");
	}
}