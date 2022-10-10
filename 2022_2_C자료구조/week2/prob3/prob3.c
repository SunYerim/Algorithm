//comment test case 모두 통과했습니다.
#define _CRT_SECURE_NO_WARNINGS
#define strdup _strdup

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(void) {

	char* words[4000];
	char buffer[20];
	int number[4000] = { 0, }; //중복 count 배열
	
	char* temp_str; // 사전식 정렬
	char* dict_str;
	int nwords = 0, step, k;
	int count1 = 0;

	FILE* fp = fopen("C://Users/Samsung/Desktop/2022 2/data_structure/week2/harry.txt", "r");

	//문자열 길이 6 이상인 단어 저장
	while (fscanf(fp, "%s", buffer) != EOF) { 
		if (strlen(strdup(buffer))>=6) {
			words[nwords] = strdup(buffer);
			nwords++;
		}
	}
	
	//사전순으로 정렬 (bubble sort)
	for (step = 0; step < nwords - 1; step++) {
		for (k = 0; k < nwords - 1 - step; k++) {
			if (strcmp(words[k], words[k + 1]) > 0) {
				temp_str = words[k];
				words[k] = words[k + 1];
				words[k + 1] = temp_str;
			}
		}
	}
	words[nwords] = "\n";
	//중복 count number
	for (int i = 0; i < nwords; i++) {
		for (int j = i; j < nwords; j++) {
			if (strcmp(words[i], words[j]) == 0)
				number[j] += 1;
		}
		
	}

	//문제 요구 답안
	for (int i = 0; i < nwords; i++) {
		int num1 = 0;
		if (strcmp(words[i], words[i+1]) == 0) {
			num1++;
		}
		else {
			
			printf("%s: %d\n", words[i], number[i + num1]);
			count1++;
		}
		
	}
	printf("%d", count1);
	fclose(fp);

	return 0;
}
