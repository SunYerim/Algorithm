//comment: duplicate ��� ���� ���� / ���� �ǵ� 80%������ �ϼ��߽��ϴ�.

#define _CRT_SECURE_NO_WARNINGS
#define MAX_COUNT 100
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void) {

	int count = 0, num, num1 = 0, insert, i;

	int data[MAX_COUNT];

	while (count < MAX_COUNT) {
		scanf_s("%d", &num);
		if (num == -1)
			exit(0);

		{
			for (int i = 0; i < num1; i++) {
				if (data[i] == num)
					printf("duplicate\n");
				continue;
			}
			num1++;


			for (insert = 0; insert < count; insert++) {
				if (num < data[insert])
					break;
			}
			for (i = count; i > insert; i--)
				data[i] = data[i - 1];

			data[insert] = num;

			count++;

			for (i = 0; i < count; i++)
				printf("%d ", data[i]);

			printf("\n");
		}
	}

	for (i = 0; i < count; i++)
		printf("%d ", data[i]);
	printf("\n");


	return 0;

}
