//comment: test case 모두 통과했습니다.
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#define swap(a, b) { int t; t = a; a = b; b = t;}

void SelectionSort(int* arr, int n);
void ViewArr(int* arr1, int n);
int main(void) {
	int num;
	scanf_s(" %d", &num);
	int* dict_arr = malloc(sizeof(int) * num);
	rewind(stdin);
	for (int i = 0; i < num; i++) {
		scanf("%d", &dict_arr[i]);
		rewind(stdin);
	
		
	}
	//fflush(stdin);

	SelectionSort(dict_arr, num);

	return 0;
}

void SelectionSort(int* arr, int n) {
	int i, j;
	int max;
	for (i = n; i > 1; i--) {
		max = 0;
		for (j = 1; j < i; j++) {
			if (arr[max] < arr[j]) {
				max = j;
			}
		}
		swap(arr[max], arr[i - 1]);

	}
	ViewArr(arr, n);
}

void ViewArr(int* arr1, int n) {
	int i = 0;
	for (i = 0; i < n; i++) {
		printf("%d ", arr1[i]);
	}
	printf("\n");
}