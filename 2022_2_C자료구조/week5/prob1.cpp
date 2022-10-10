//comment: testcase 모두 통과했습니다.
#define _CRT_SERCURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
int alpha(char x); //자음이면 1, 모음이면 0 반환

int main(void){
    //문자열 입력 받고, 자음.모음 판별 함수 생성1, count변수 가장 큰 것
    char x, string[100], store_str[100]; //자음 가장 여러 번 등장 부분
    int store_num[100];
    int start = 0, end = 0; //가장 긴 자음구간의 시작점. 끝점
    int pre_start, count = 0; //현재 돌고있는 시작점, count

    scanf("%s", &string);
   
    for (int i = 0; i < strlen(string); i++){
        //pre_start = i;
        for (int j = i; j < strlen(string); j++){
            if (alpha(string[j]) == 0){
                break;
            }
            if (alpha(string[j]) == 1){
                count++;
            }
        }
        store_num[i] = count;
    }
    //store_num[i]-store_num[i-1] 의 최댓값과 그때의 i값을 저장해두면 됨.
    int max_index = 0, num_sub=0;
    for (int i = 1; i < strlen(string); i++){
        if (store_num[i]-store_num[i-1] > num_sub){
            num_sub = store_num[i]-store_num[i-1];
            max_index = i;
        }
    }
    

    for (int i = max_index; i < max_index + num_sub; i++){
        printf("%c", string[i]);

    }
    
    
    
    return 0;
}

int alpha(char x){ //자음 1, 모음 0 판별코드
    int num = 0, num1 = 1;
    switch(x){
        case 'a':
            return num;
            break;
        case 'e':
            return num;
            break;
        case 'i':
            return num;
            break;
        case 'o':
            return num;
            break;
        case 'u':
            return num;
            break;
        default:
            return num1;
            break;
    }
}