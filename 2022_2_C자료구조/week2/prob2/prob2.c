//comment test case 모두 통과했습니다.
#define _CRT_SECURE_NO_WARNINGS
#define strdup _strdup

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(void) {

	char* words[20000];
	char buffer[20];
	int number[20000] = { 0, }; //중복 count 배열
	char* distinct_words[2800]; //중복제거 배열
	char* temp_str; // 사전식 정렬
	int nwords = 0, step, k;

	FILE* fp = fopen("C://Users/Samsung/Desktop/2022 2/data_structure/week2/harry.txt", "r");


	while (fscanf(fp, "%s", buffer) != EOF) {
		words[nwords] = strdup(buffer);
		nwords++;
	}

	for (int i = 0; i < nwords; i++) {
		for (int j = i; j < nwords; j++) {
			if (strcmp(words[i], words[j]) == 0)
				number[j] += 1;
		}
	}

	int n = 0;
	for (int i = 0; i < nwords; i++) {
		if (number[i] == 1) {
			distinct_words[n++] = words[i];
		}
	}

	//중복 제거 후 사전순으로 정렬 (bubble sort)
	for (step = 0; step < n - 1; step++) {
		for (k = 0; k < n - 1 - step; k++) {
			if (strcmp(distinct_words[k], distinct_words[k + 1]) > 0) {
				temp_str = distinct_words[k];
				distinct_words[k] = distinct_words[k + 1];
				distinct_words[k + 1] = temp_str;
			}
		}
	}

	char* prefix = malloc(sizeof(char) * 5);
	scanf("%s", prefix);



	int count = 0;
	for (int i = 0; i < n; i++) {
		if (strncmp(prefix, distinct_words[i], strlen(prefix)) == 0) {
			printf("%s\n", distinct_words[i]);
			count++;
		}
	}
	printf("%d", count);


	fclose(fp);

	return 0;
}
