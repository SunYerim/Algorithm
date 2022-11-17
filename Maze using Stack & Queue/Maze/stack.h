#ifndef STACK_H
#define STACK_H

#include <stdbool.h>
#include "pos.h"

typedef Position Item;

typedef struct stack_type *Stack;

Stack create();
void destroy(Stack s);
void make_empty(Stack s);
bool is_empty(Stack s);
void push(Stack s, Item i);
void pop(Stack s);
Item peek(Stack s);

#endif
