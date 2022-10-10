#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//void add_word(char* word, char* word_explain, int n);

//file 읽을때, fgets로 buff에 한 줄씩 담아서 => token 분리 => 각자 배열로 들여보냄(들여보낼때 sorting_words에서 먼저.)

int main(void) {
	char* word_arr[10000]; //단어 저장 배열
	char* explan_arr[10000]; //설명 저장 배열
	char* buff[5000];
	char* token, * token1;
	int count = 0;
	

	FILE* in_fp = fopen("C://Users/Samsung/Desktop/2022 2/data_structure/week3/shuffled_dict.txt", "r");
	FILE* out_fp = fopen("C://Users/Samsung/Desktop/2022 2/data_structure/week3/sorted_dict.txt", "w");

	
	while (fgets(buff, sizeof(buff), in_fp)) {
		token = strtok(buff, "\t");
		token1 = strtok(buff, "\n");
		//printf("%s\n", token1);

		while (token != NULL) {
			
			word_arr[count] = token;
			count++;
			token = strtok(NULL, "\t\n");
			//explan_arr[count1++] = token;
			//token = strtok(NULL, "\t\n");
			//token1 = strtok(NULL, "\n");

			
			//printf("%s: %s\n", word_arr[0], explan_arr[0]);
			//explan_arr[count1++] = token;
			//token = strtok(NULL, "\t\n");


		}
	}
	
	
	
	fclose(in_fp);

		
	return 0;
	
}


/*

void sorting_words(char* word, int n) { //사전식 정렬_다시
	char* temp_str;
	for (int step = 0; step < n - 1; step++) {
		for (int k = 0; k < n - 1 - step; k++) {
			if (strcmp(word[k], word[k + 1]) > 0) {
				temp_str = word[k];
				word[k] = word[k + 1];
				word[k + 1] = temp_str;
			}
		}
	}
}*/