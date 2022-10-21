//testcase 모두 통과하였습니다.
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	
	int num;
	scanf("%d", &num);
	int num_array[100];
	int num_array2[100]; //각 array에 들어있는 수들 끝자리 수 넣어놓기
	//array에 넣어줌
	for (int i = 0; i < num; i++) {
		scanf("%d", &num_array[i]);
	}
	//끝자리 수도 새로운 배열에 넣어줌
	for (int i = 0; i < num; i++) {
		int end_num = num_array[i] % 10;
		num_array2[i] = end_num;
	}
	//같이 swap
	for (int i = num - 1; i > 0; i--) {
		int max_index = 0;
		for (int j = 0; j <= i; j++) {
			if (num_array2[j] > num_array2[max_index])
				max_index = j;
		}
		int tmp = num_array2[i];
		int tmp1 = num_array[i];

		num_array2[i] = num_array2[max_index];
		num_array[i] = num_array[max_index];

		num_array2[max_index] = tmp;
		num_array[max_index] = tmp1;

	}
	printf("\n");
	//swap은 됐는데 숫자 똑같을 때 나머지 수 비교
	for (int i = 1; i < num; i++) {
		if (num_array2[i - 1] == num_array2[i] && num_array[i - 1] > num_array[i]) {
			int tmp = num_array[i - 1];
			int tmp2 = num_array2[i - 1];

			num_array[i - 1] = num_array[i];
			num_array2[i - 1] = num_array2[i];

			num_array[i] = tmp;
			num_array2[i] = tmp2;
		}
		else {
			continue;
		}
	}
	for (int i = 0; i < num; i++) {
		printf("%d\n", num_array[i]);
	}
	

	
	return 0;
}


