#include <stdio.h>

void maxmin(int prob1, int prob2, int prob3, int *max, int *min);
int ErrorTest(int *x, int *y, int *z, int count);

int main() {
    int x, y, z;
    int count = 3;
    if (ErrorTest(&x, &y, &z, count)) {
        printf("n/a");
    } else {
        int max, min;
        maxmin(x, y, z, &max, &min);
        printf("%d %d", max, min);
    }
    return 0;
}

void maxmin(int prob1, int prob2, int prob3, int *max, int *min) {
    *max = *min = prob1;
    if (prob2 > *max) {
        *max = prob2;
    }
    if (prob2 < *min) {
        *min = prob2;
    }
    if (prob3 > *max) {
        *max = prob3;
    }
    if (prob3 < *min) {
        *min = prob3;
    }
}

int ErrorTest(int *x, int *y, int *z, int count) {
    char test;
    int result = 0;
    count = scanf("%d %d %d%c", x, y, z, &test);
    if (count < 3) {
        result = 1;
    } else if (count == 4 && test != '\n' && test != ' ' && test != '\t') {
        result = 1;
    } else if (count == 4 && (test == ' ' || test == '\t')) {
        char next_char;
        while ((next_char = getchar()) != '\n' && next_char != EOF) {
            if (next_char != ' ' && next_char != '\t') {
                result = 1;
            }
        }
    }
    return result;
}
