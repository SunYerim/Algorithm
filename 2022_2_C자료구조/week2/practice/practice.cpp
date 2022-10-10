#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#include <string.h>


int main(void) {
	
	int num[100];
	int n = 0, k;

	while (1) {
		scanf("%d", &k);
		if (k == -1)
			break;
		bool duplicate = false;
		for (int i = 0; i < n; i++) {
			if (num[i] == k) {
				printf("duplicate\n");
				duplicate = true;
				break;
			}
		}
		if (!duplicate) {
			int j = n - 1;
			//insert
			while (j >= 0 && num[j] > k) {
				num[j + 1] = num[j];
				j--;

			}
			num[j + 1] = k;
			n++;

			for (int i = 0; i < n; i++)
				printf("%d ", num[i]);
			printf("\n");
		}
	}
	return 0;
}
