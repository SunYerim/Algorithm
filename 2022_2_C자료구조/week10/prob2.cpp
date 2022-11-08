/*test case 모두 통과했습니다.*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define max_size 100

typedef int Item;
struct stack_type { //stack 구조체
    char *name; // stack의 이름
	char *data[max_size];
	int top;
};

typedef struct stack_type *Stack;

void init(Stack s) {
	s->top = -1;
}

void push(Stack s, char* item) {
	s->data[++(s->top)] = item;
    
}

bool is_empty(Stack s) {
	return s->top == -1;
}

char *pop(Stack s) {
    char *t = s->data[s->top];
	s->data[s->top] = 0;
	s->top--;
	return t;
}

char *peek(Stack s){
    return s->data[s->top];
}

Stack create(char *stackName){
    
    Stack s = (Stack)malloc(sizeof(stack_type));
    s->name = stackName;
    s->top = -1;

    return s;
}


int main(void){
    /*stack들을 담을 배열과 stack의 name이 들어갈 배열 생성*/
    //Stack stacks[10]; // stack들을 담을 배열
    //char* stackName[10]; // stack의 name이 들어갈 배열 생성
    Stack stacks[max_size];
    int n = 0;

    char prompt[100];
    char *command, *name, *item;

    while (true){
        printf("$ ");
        fgets(prompt, sizeof(prompt), stdin);

        if(prompt[strlen(prompt) - 1] == '\n')
            prompt[strlen(prompt) - 1] = '\0';
        
        command = strtok(prompt, " ");
        
        if (strcmp(command, "create") == 0){
            name = strtok(NULL, " ");
            stacks[n] = create(strdup(name));
            n++;
        }

        else if (strcmp(command, "push") == 0){
            name = strtok(NULL, " ");
            item = strtok(NULL, " ");
            for (int i = 0; i < n; i++){
                if (strcmp(name, stacks[i]->name) == 0){
                    push(stacks[i], strdup(item));
                    break;
                }
            }
        }

        else if (strcmp(command, "pop") == 0){
            name = strtok(NULL, " ");
            for (int i = 0; i < n; i++){
                if (strcmp(name, stacks[i]->name) == 0){
                    printf("%s\n", pop(stacks[i]));
                    
                    break;
                }  
            }
        }

        else if (strcmp(command, "list") == 0){
            name = strtok(NULL, " ");
            for (int i = 0; i < n; i++){
                if (strcmp(name, stacks[i]->name) == 0){
                    for (int j = stacks[i]-> top; j >= 0; j--){
                        printf("%s\n", stacks[i]->data[j]);
                    }
                    break;
                }    
            }
        }

        else if (strcmp(command, "exit") == 0){
            break;
        }
    }

    return 0;

}
