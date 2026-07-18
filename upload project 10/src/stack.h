#ifndef STACK_H
#define STACK_H

#define SUCCESS "SUCCESS"
#define FAIL "FAIL"

struct node {
    int value;
    struct node* next;
};

struct stack {
    struct node* top;
};

struct stack* init();
int push(struct stack* s, int value);
int pop(struct stack* s, int* value);
void destroy(struct stack* s);

#endif
