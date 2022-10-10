//comment: testcase 모두 통과했습니다 교수님.
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void colmax();
void colmin();
void rowmax();
void rowmin();

int main(void){
    int rows_cols;
    char command[100];
    FILE *file = fopen("data.mat", "r");
    fscanf(file, "%d\n", &rows_cols);
    int num_arr[100][100];

    for (int i = 0; i < rows_cols; i++){
        for (int j = 0; j < rows_cols; j++){
            fscanf(file, "%d", &num_arr[i][j]);
        }
    }
    while(1){
        printf("$");
        scanf("%s", &command);
   
        if (strcmp(command, "show") == 0){ // 행렬을 출력함.
            for (int i = 0; i < rows_cols; i++){
                for (int j = 0; j < rows_cols; j++){
                    printf("%d ", num_arr[i][j]);
                }
                printf("\n");
            }
        }

        if (strcmp(command, "colmax") == 0){
            for (int i = 0; i < rows_cols; i++){ //행
                int max_num = -9999;
                for (int j = 0; j < rows_cols; j++){ //각 열
                    if (max_num < num_arr[j][i]){
                        max_num = num_arr[j][i];
                    }
                }
                printf("%d ", max_num);
            }
            printf("\n");   
        }

        if (strcmp(command, "colmin") == 0){
            for (int i = 0; i < rows_cols; i++){ //행
                int min_num = 9999;
                for (int j = 0; j < rows_cols; j++){
                     //각 열
                    if (min_num > num_arr[j][i]){
                        min_num = num_arr[j][i];
                    }
                }
                printf("%d ", min_num);
            }
            printf("\n");
        }

        if (strcmp(command, "rowmax") == 0){
            for (int i = 0; i < rows_cols; i++){ //열
                int max_num = -9999;
                for (int j = 0; j < rows_cols; j++){ //각 행
                    if (max_num < num_arr[i][j]){
                        max_num = num_arr[i][j];
                    }
                }
                printf("%d ", max_num);
            }
            printf("\n");
        }

        if (strcmp(command, "rowmin") == 0){
            for (int i = 0; i < rows_cols; i++){ //열
                int min_num = 9999;
                for (int j = 0; j < rows_cols; j++){ //각 행
                    if (min_num > num_arr[i][j]){
                        min_num = num_arr[i][j];
                    }
                }
                printf("%d ", min_num);
            }
            printf("\n");
        }

        if (strcmp(command, "slice") == 0){
            int x, p, y, q;
            scanf("%d %d %d %d", &x, &p, &y, &q);
            int n = 0;
            for (int i = 0; (x+(i*p)) < rows_cols; i++){
                for (int j = 0; (y+(j*q)) < rows_cols; j++){
                    printf("%d ", num_arr[x+(i*p)][y+(j*q)]);
                }
                //n++;
                //printf("%d", n);
                printf("\n");
            }
            
        }

        if (strcmp(command, "exit") == 0){
            exit(0);
        }
    }
    fclose(file);
    return 0;
}