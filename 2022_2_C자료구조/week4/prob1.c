//comment: testcase 모두 통과했습니다.
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main(void){
    //num받아서, malloc 저장 후 역전된 쌍 개수 return -> 이중 for문
    int input_size = 0, input_value, max_num, count = 0;
    int *size = NULL;
    scanf("%d", &input_size);

    int num_array = malloc(sizeof(input_size));// 숫자

    size = (int *)malloc(sizeof(int) * input_size);

    for (int i = 0 ; i < input_size; i++){
        scanf("%d", &input_value);
        *(size + i) = input_value;
        //rewind(stdin);
        
    }

    for (int i = 0; i < input_size; i++){
        max_num = size[i];
        for (int j = i; j < input_size; j++){
            if (max_num > size[j]){
                count++;
            }
        }
        
    }
    printf("%d\n", count);

    
    return 0;


}