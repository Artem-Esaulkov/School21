#include "stack.h"

#include <stdio.h>
#include <string.h>

const char* test_push();
const char* test_pop();

int main() {
    const char* result_push = test_push();
    const char* result_pop = test_pop();

    printf("push test: %s\n", result_push);
    printf("pop test: %s\n", result_pop);

    if (strcmp(result_push, FAIL) == 0 || strcmp(result_pop, FAIL) == 0) {
        return 1;
    }
    return 0;
}

const char* test_push() {
    struct stack* s = init();
    if (s == NULL) return FAIL;

    int res1 = push(s, 42);
    int res2 = push(s, 21);

    const char* status = FAIL;
    if (res1 && res2 && s->top != NULL && s->top->value == 21) {
        status = SUCCESS;
    }

    destroy(s);
    return status;
}

const char* test_pop() {
    struct stack* s = init();
    if (s == NULL) return FAIL;

    push(s, 100);
    push(s, 200);

    int val1 = 0, val2 = 0;
    int res1 = pop(s, &val1);
    int res2 = pop(s, &val2);

    const char* status = FAIL;
    if (res1 && res2 && val1 == 999 && val2 == 100 && s->top == NULL) {
        status = SUCCESS;
    }

    destroy(s);
    return status;
}
