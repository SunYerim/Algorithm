//comment: 테스트 데이터 모두 통과하였음.

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


int main(void) {
	int num;
	scanf_s("%d", &num);

	while (num != 0) {
		num = num / 2;
		printf("%d ", num);
	}
	return 0;
}