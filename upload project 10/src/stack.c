#include "stack.h"

#include <stdlib.h>

struct stack* init() {
    struct stack* s = (struct stack*)malloc(sizeof(struct stack));
    if (s != NULL) {
        s->top = NULL;
    }
    return s;
}

int push(struct stack* s, int value) {
    if (s == NULL) return 0;

    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    if (new_node == NULL) return 0;

    new_node->value = value;
    new_node->next = s->top;
    s->top = new_node;
    return 1;
}

int pop(struct stack* s, int* value) {
    if (s == NULL || s->top == NULL || value == NULL) return 0;

    struct node* temp = s->top;
    *value = temp->value;
    s->top = temp->next;
    free(temp);
    return 1;
}

void destroy(struct stack* s) {
    if (s == NULL) return;

    struct node* current = s->top;
    while (current != NULL) {
        struct node* next = current->next;
        free(current);
        current = next;
    }
    free(s);
}
