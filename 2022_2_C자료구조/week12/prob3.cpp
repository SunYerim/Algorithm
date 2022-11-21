/*test case 모두 통과했습니다.*/
#include <stdio.h>
#define MAX 1000

int twoSum(int data[], int begin, int end, int K);
int count = 0;
int main(void){

    int data[MAX];
    int N, K;

    scanf("%d", &N);

    int start = 0, end = N -1;
    
    for (int i = 0; i < N; i++){
        scanf("%d", &data[i]);
    } // 배열 저장

    scanf("%d", &K);

    printf("%d", twoSum(data, start, end, K));
    return 0;
}


int twoSum(int data[], int begin, int end, int K){
     if (begin >= end){
        return count;
    }
    else {
        if (data[begin] + data[end] == K){
            return twoSum(data, begin+1, end-1, K);
        }
        else if (data[begin] + data[end] < K)
            return twoSum(data, begin+1, end, K);
        else
            return twoSum(data, begin, end-1, K);
    
    }
    
}



