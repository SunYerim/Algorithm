/*test case 모두 통과했습니다.*/
#include <stdio.h>
#include <string.h>

#define max_size 100

typedef struct Stack {
	int stack[max_size];
	int top;
}Stack;

void Stack_init(Stack* s) {
	s->top = -1;
}

void Stack_push(Stack* s, int item) {
	s->stack[++(s->top)] = item;
	return;
}

bool is_empty(Stack* s) {
	return s->top == -1;
}

int Stack_pop(Stack* s) {
	int t = s->stack[s->top];
	s->stack[s->top] = 0;
	s->top--;
	return t;
}

int main(void) {

    char OPEN[] = "([{";
    char CLOSE[] = ")]}";
    int num = 0;

	Stack s;
	Stack_init(&s);

    char string_buff[max_size];
    scanf("%s", string_buff);   // 문자열 입력 받는 배열

	char input[max_size];

    /*input 배열에 괄호만 남도록 해주는 작업*/
    for (int i = 0; i < strlen(string_buff); i++){
        if (string_buff[i] == OPEN[0] || string_buff[i] == CLOSE[0]){
            input[num++] = string_buff[i];
        }
        else
            continue;
    }

    
    /*괄호 순서 print*/
	int i = 0, count = 1;
	while (input[i] != NULL) {
		if (input[i] == '(') {
			Stack_push(&s, count); //stack에 push
			printf("%d ", count);
			count++;
		}
		else {
			printf("%d ", Stack_pop(&s));
		}
		i++;
	}

	return 0;
}