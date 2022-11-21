/*test case 모두 통과하였습니다.*/
#include <stdio.h>
#define MAX 1000

int floor(int data[], int start, int end, int num);
int ceiling(int data[], int start, int end, int num);

int main(void){

    int data[MAX];
    int N, K;

    scanf("%d", &N);

    int start = 1, end = N-1;
    
    for (int i = 0; i < N; i++){
        scanf("%d", &data[i]);
    } // 배열 저장

    scanf("%d", &K);

    printf("%d\n", floor(data, start, N-1, K));
    printf("%d\n", ceiling(data, start, N-1, K));

    return 0;
}


int floor(int data[], int start, int end, int num){
    if (start <= end){
        if ((data[start] <= num && data[start+1] >= num ) || ((start == end) && (data[end] <= num)))
            return data[start];
        else{
            return floor(data, start+1, end, num);
        }
    }
    else
        return -1;
    
}

int ceiling(int data[], int start, int end, int num){
    if (start <= end){
        if ((data[start] >= num && data[start-1] <= num) || ((start == end) && (data[end] >= num)))
            return data[start];
        else{
            return  ceiling(data, start+1, end, num);
        }
    }
    else
        return -1;

}