//comment: 테스트 데이터 모두 통과하였습니다.
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
	int len;
	char str[51];
}words;

int compare(const void* a, const void* b) {
	words real_a = *(words*)a;
	words real_b = *(words*)b;
	int len_a = strlen(real_a.str);
	int len_b = strlen(real_b.str);
	if (len_a != len_b)
		return (len_a - len_b);
	return strcmp(real_a.str, real_b.str);
}

int main()
{
	words* word;
	words tmp;
	int flag = 0, real_n = 0;
	char strtmp[51] = { 0 };
	int n, i, j;
	scanf("%d", &n);
	word = (words*)malloc(sizeof(words) * n);
	for (i = 0; i < n; i++)
	{
		scanf("%s", strtmp);
		for (j = 0; j < i; j++) {
			if (strcmp(word[j].str, strtmp) == 0) {
				flag = 1;
				break;
			}
		}
		if (flag == 0) {
			strcpy(word[real_n].str, strtmp);
			word[real_n].len = strlen(strtmp);
			real_n++;
		}
		flag = 0;
	}
	qsort(word, real_n, sizeof(words), compare);
	printf("\n");
	for (i = 0; i < real_n; i++)
		printf("%s\n", word[i].str);
	
	free(word);
	return 0;
}