#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    //num�޾Ƽ�, malloc ���� �� ������ �� ���� return -> ���� for��
    int input_size = 0, input_value;
    int* size = NULL;
    input_size = scanf("%d", &input_size);
    rewind(stdin);

    //int num_array = malloc(sizeof(input_size));// ����

    size = (int*)malloc(sizeof(int) * input_size);

    for (int i = 0; i < input_size; i++) {
        scanf("%d", &input_value);
        *(size + i) = input_value;
        rewind(stdin);
    }

    /*for (int j = 0; j < input_size; j++) {
        printf("%d\n", *(size + j));
    }*/


    return 0;


}