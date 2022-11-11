/*test case 모두 통과했습니다.*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define max_size 1000000

typedef int Item;
struct stack_type { //stack 구조체
	Item data[max_size];
    Item smaller_num[max_size] = { 0, }; // 나보다 작거나 같은 데이터가 몇 개인지 저장
	int top;
};

typedef struct stack_type *Stack;

void push(Stack s, int item, int count) {
    s->top++;
    s->smaller_num[(s->top)] = count;
	s->data[(s->top)] = item;
}

bool is_empty(Stack s) {
	return s->top == -1;
}

void pop(Stack s) {
	s->data[s->top] = 0;
    s->smaller_num[s->top] = 0;
	s->top--;
}

Item peek(Stack s){
    return s->data[s->top];
}

Stack create(){
    Stack s = (Stack)malloc(sizeof(stack_type));
    s->top = -1;
    return s;
}

void make_empty(Stack s){
    s->top = -1;
}

int main(void){

    time_t start = time(NULL);

    int T = 0;
    FILE *file = fopen("input.txt", "r");
    fscanf(file, "%d\n", &T); // 첫 줄
    
    Stack s; // 스택 생성
    s = create();

    int N; // 총 몇 개의 data를 받아와야되는가
    
    for (int i = 0; i < T; i++){
        fscanf(file, "%d\n", &N);

        int number; // 각각의 data
        int sum = 0;

        for (int j = 0; j < N; j++){
        
            int count = 0;
            fscanf(file, "%d ", &number);

            while(true){
                if (is_empty(s) || peek(s) > number){
                    push(s, number, count);
                    sum += count;
                    break;
                }
                ++count += s->smaller_num[s->top];
                pop(s);
            }
            sum %= 1000000;   
        }
        printf("%d\n", sum); 

        make_empty(s); // 스택 비워주기
    }
    
    time_t end = time(NULL);

    printf("%f", (double) (end-start) / CLOCKS_PER_SEC);
    return 0;
}

/*push 하면서 앞에 꺼 비교 후 작거나 같으면 smaller_num 배열에 값 저장 해주고, pop 해줄 때 smaller_num 배열에 있는 값 return_num에 더해주고 pop 시켜줌 */
