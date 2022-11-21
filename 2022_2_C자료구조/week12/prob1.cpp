/*test case 모두 통과했습니다.*/

#include <stdio.h>
#include <string.h>

bool is_palindrome(char str[], int start, int end);

int main(void){

    char string[100];
    scanf("%s", &string);

    if (is_palindrome(string, 0, strlen(string))){
        printf("Yes.\n");
    }
    else{
        printf("No.\n");
    }
    
    return 0;
}

bool is_palindrome(char str[], int start, int end){
    if (strlen(str) == 1){ //문자열의 길이가 1인경우
        return true;
    }

    if (str[start] != str[end-1]) // 첫글자와 마지막 글자가 다른 경우
        return false;

    if (start < end + 1){ // 점점 범위 좁혀가는 형식으로
        return is_palindrome(str, start + 1, end - 1);
    }
    
    return true;
}

