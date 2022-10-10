//comment: 테스트 데이터 모두 통과하였음.

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void) {
	int num1, k,  minimum, ans_num;
	scanf_s("%d", &num1);


	int* num_list;
	num_list = (int*)malloc(num1 * sizeof(int));

	for (int i = 0; i < num1; i++) {
		scanf_s("%d", &num_list[i]);

	}

	scanf_s("%d", &k);

	//절댓값 계산
	minimum = abs(num_list[0] - k);
	ans_num = num_list[0];
	for (int i = 0; i < num1; i++) {

		int abs_num = abs(num_list[i] - k);
		if (abs_num < minimum) {
			minimum = abs_num;

			ans_num = num_list[i];
		}
		
	}
	printf("%d\n", ans_num);
	free(num_list);

	return 0;
}