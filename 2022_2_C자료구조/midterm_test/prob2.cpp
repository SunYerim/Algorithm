//testcase 모두 통과했습니다.
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main(void) {
	int num;
	int count = 0;
	char tmp[100];
	char word[20]; //검색할 단어
	char *word2; //swap할 때 필요

	scanf("%d", &num);

	char *words[100];
	//배열에 저장
	while (count < num && scanf("%s", tmp) != EOF) {
		words[count] = _strdup(tmp);
		count++;
	}

	//배열 사전식 정렬
	for (int i = num - 1; i > 0; i--) {
		int max_index = 0;
		for (int j = 0; j <= i; j++) {
			if (strcmp(words[j], words[max_index])>0)
				max_index = j;
		}
		word2 = words[i];
		words[i] = words[max_index];
		words[max_index] = word2;

	}
	
	int ans_count = 0;
	scanf("%s", &word); //검색할 단어\

	//검색할 단어와 가장 가까이 있는 단어 print
	for (int i = 1; i < num; i++) {
		if (strcmp(word, words[i-1]) > 0 && strcmp(word, words[i]) < 0) {
			printf("%s\n", words[i]);
			ans_count++;
			break;
		}
	}
	if (ans_count == 0) {
		printf("%s", "None");
	}
	
	

	return 0;
}