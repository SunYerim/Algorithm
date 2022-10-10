//comment: testcase 모두 통과하였습니다.
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main(void){
    //첫번째 줄 읽어서 num, 한 줄씩 읽어서 num_arr에 저장 후 평균.표준편차 계산
    //fscanf && 이중 for문 사용 
    int num_arr[100][100];
    int number,  num, number1;
    

    FILE *file = fopen("input.txt", "r");
    while (!feof(file)){
        fscanf(file, "%d", &num);
        printf("%d\n", num);
    
        //배열 저장
        for (int i = 0; i < num; i++){
            for (int j = 0; j < num; j++){
                fscanf(file, "%d", &num_arr[i][j]);
            }
        }


        //행
        for (int i = 0; i < num; i++){
            int sum = 0;
            double sqrt_sum = 0.0;
            float avg;
            for (int j = 0; j < num; j++){
                sum += num_arr[i][j];
                printf("%d ", num_arr[i][j]);
            }
            avg = (float)sum / num;
            printf("%.2f ", avg);
            

            for (int k = 0; k < num; k++){
                sqrt_sum += (num_arr[i][k] - avg) * (num_arr[i][k]-avg);
            }
            printf("%.2f", sqrt(sqrt_sum / num));
            printf("\n");
        
        }

        //열
        float avg;
        for (int i = 0; i < num; i++){
            int sum = 0;
            
            
            for (int j = 0; j < num; j++){
                sum += num_arr[j][i];
            }
            avg = (float)sum / num;
            printf("%.2f ", avg);
        }
        printf("\n");
        for (int i = 0; i < num; i++){
            double sqrt_sum = 0.0;
            for (int k = 0; k < num; k++){
                sqrt_sum += (num_arr[k][i] - avg) * (num_arr[k][i]-avg);
            }
            printf("%.2f ", sqrt(sqrt_sum / num));
            
        }

   
    }
    

    return 0;


    fclose(file);
}
