#include <stdio.h>
#define NMAX 10

int input(int *a, int *n);
void output(int *a, int *n);
void squaring(int *a, int *n);
int ErrorTest(int *a, int *n);

int main() {
    int n, data[NMAX];
    if (input(data, &n) == 1) {
        printf("n/a");
    } else {
        squaring(data, &n);
        output(data, &n);
    }
    return 0;
}

int input(int *a, int *n) {
    int result = 0;
    char c;
    if (scanf("%d%c", n, &c) != 1 && c != '\n') {
        result = 1;
    }
    if (ErrorTest(a, n)) {
        result = 1;
    }
    return result;
}

void output(int *a, int *n) {
    for (int i = 0; i < *n; i++) {
        if (i != (*n - 1)) {
            printf("%d ", a[i]);
        } else {
            printf("%d", a[i]);
        }
    }
}

void squaring(int *a, int *n) {
    for (int i = 0; i < *n; i++) {
        a[i] = a[i] * a[i];
    }
}

int ErrorTest(int *a, int *n) {
    int result = 0;
    int counter = 0;
    if (*n <= 0 || *n > NMAX) {
        result = 1;
    } else {
        for (int *p = a; p - a < *n; p++) {
            if (scanf("%d", p) == 1) {
                counter++;
            } else {
                result = 1;
            }
        }
        if (counter < *n) {
            result = 1;
        }
        char next_char;
        while ((next_char = getchar()) != '\n' && next_char != EOF) {
            if (next_char != ' ' && next_char != '\t') {
                result = 1;
            }
        }
    }
    return result;
}
