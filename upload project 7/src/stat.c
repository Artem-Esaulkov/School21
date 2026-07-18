#include <stdio.h>
#define NMAX 10

int input(int *a, int *n);
int ErrorTest(int *a, int *n);
void output(int *a, int *n);
int max(int *a, int *n);
int min(int *a, int *n);
double mean(int *a, int *n);
double variance(int *a, int *n);
void output_result(int max_v, int min_v, double mean_v, double variance_v);

int main() {
    int n, data[NMAX];
    if (input(data, &n) == 1) {
        printf("n/a");
    } else {
        output(data, &n);
        output_result(max(data, &n), min(data, &n), mean(data, &n), variance(data, &n));
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

void output(int *a, int *n) {
    for (int i = 0; i < *n; i++) {
        if (i != (*n - 1)) {
            printf("%d ", a[i]);
        } else {
            printf("%d\n", a[i]);
        }
    }
}

int max(int *a, int *n) {
    int result = a[0];
    for (int i = 1; i < *n; i++) {
        if (a[i] > result) {
            result = a[i];
        }
    }
    return result;
}

int min(int *a, int *n) {
    int result = a[0];
    for (int i = 1; i < *n; i++) {
        if (a[i] < result) {
            result = a[i];
        }
    }
    return result;
}

double mean(int *a, int *n) {
    double result;
    result = (max(a, n) + min(a, n)) / 2.0;
    return result;
}

double variance(int *a, int *n) {
    double result;
    result = ((max(a, n) - min(a, n) + 1) * (max(a, n) - min(a, n) + 1) - 1) / 12.0;
    return result;
}

void output_result(int max_v, int min_v, double mean_v, double variance_v) {
    printf("%d %d %.6lf %.6lf", max_v, min_v, mean_v, variance_v);
}
