//comment: testcase 모두 잘 통과했습니다!
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main(void){
    char buff[200]; //한 줄씩 읽을 때 임시 저장 공간
    char *token;
    char *sentence_arr[500];
    int count = 0;
    FILE *file = fopen("sample.html", "r");
    FILE *re_file = fopen("sample.txt", "w+");

    char *couple_str[4]={"div", "strong", "br", "span"}; //해당되는 문자열 포함 시 continue

    //token 끊어서 < > 제거
    while (fgets(buff, sizeof(buff), file)){
        token = strtok(buff,"</>");
        while (token != NULL){
            int num = 0;
            for (int i = 0; i < 4; i++){
                if(strncmp(token, couple_str[i], strlen(couple_str[i]))==0){
                    num++;
                }  
            }
            if (num != 1){
                sentence_arr[count++] = strdup(token);  
            }
            token = strtok(NULL, "</>");             
        }
    }
    //sentence_arr을 fprintf이용하여 sample.txt로 저장시킴
    for (int i = 0; i < count; i++){
        fprintf(re_file, "%s", sentence_arr[i]);
    }
    fclose(file);
    fclose(re_file);
    return 0;
}