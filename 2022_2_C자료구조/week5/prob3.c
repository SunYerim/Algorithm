//comment: test case 모두 통과했습니다.
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
const int dy[4] = { 1, 1, 0, -1 };
const int dx[4] = { 0, 1, 1, 1 };

//좌표 잡아서 4방향 탐색 if 똑같은 돌 놓여있으면==>한 방향으로 쭉 탐색. 5개 놓여있는지 (육목 경우 제외)
int main(void){
    int rows_cols, rx=0, ry=0;
    int num_arr[19][19];
    FILE *file = fopen("board.txt", "r");
    fscanf(file, "%d\n", &rows_cols);
    
    //num_arr에 배열 저장
    for (int i = 0; i < rows_cols; i++){
        for (int j = 0; j < rows_cols; j++){
            fscanf(file, "%d", &num_arr[i][j]);
        }
    }

    //오목 승부 판별
    for (int rx = 0; rx < 20; rx++){
        for (int ry = 0; ry < 20; ry++){
            int check = num_arr[ry][rx];
            if (check){
                for (int i = 0; i < 4; i++){
                    int r = 0;
                    for (int k = 0; num_arr[ry+dy[i] * k][rx + dx[i] * k] == check; k++){
                        if (num_arr[ry - dy[i]][rx - dx[i]] == check){
                            break;
                        }
                        r++;
                    }
                    if (r == 5){
                        if (check == 1){
                            printf("%s", "Black");
                        }
                        else if (check == 2){
                            printf("%s", "White");
                        }
                        
                        return 0;
                    }
                }
            }
        }    
    }
    printf("%s", "Not Finished");              
    return 0;

}

