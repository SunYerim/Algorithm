//comment: 테스트 데이터 모두 통과하였음.

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int n = 1;
	int num1;
	scanf_s("%d", &num1);


	int* num_list;
	int* num_list2;
	num_list = (int*)malloc(num1 * sizeof(int));
	num_list2 = (int*)malloc(num1 * sizeof(int)); //중복제거 list

	for (int i = 0; i < num1; i++) {
		scanf_s("%d", &num_list[i]);

	}

	//배열 오름차순 정렬
	for (int i = 0; i < num1 - 1; i++) {
		for (int j = 0; j < num1 - i - 1; j++) {
			if (num_list[j] > num_list[j + 1]) {
				int temp = num_list[j];
				num_list[j] = num_list[j + 1];
				num_list[j + 1] = temp;
			}
		}
	}

	num_list2[0] = num_list[0];
	
	for (int i = 1; i < num1; i++) {
		if (num_list[i] != num_list2[n - 1])
			num_list2[n++] = num_list[i];
	}
	printf("%d :", n);
	for (int i = 0; i < n; i++) {
		printf("%d ", num_list2[i]);
	}
	printf("\n");

	free(num_list);

	return 0;
}