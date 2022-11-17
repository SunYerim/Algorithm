#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#include "pos.h"

struct stack_type {
    Item data[50]; // x, y 좌표 동시 저장됨.
    int top;
};

void push(Stack s, Item item) {
    s->top++;
    s->data[(s->top)] = item;
}

bool is_empty(Stack s) {
    return s->top == -1;
}

void pop(Stack s){
    s->data[(s->top)].x = 0;
    s->data[(s->top)].y = 0;
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



