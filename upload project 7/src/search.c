#include <math.h>
#include <stdio.h>
#define NMAX 30

int input(int *a, int *n);
int ErrorTest(int *a, int *n);
int max(int *a, int *n);
int min(int *a, int *n);
double mean(int *a, int *n);
int InThreeSigm(int num, int *a, int *n);
int DesiredNumber(int *a, int *n);
void output(int *a, int *n);

int main() {
    int n, data[NMAX];
    if (input(data, &n) == 1) {
        printf("n/a");
    } else {
        output(data, &n);
    }
    return 0;
}

int input(int *a, int *n) {
    int result = 0;
    char c;
    if (scanf("%d%c", n, &c) != 1 && c != '\n') {
        result = 1;
    } else if (ErrorTest(a, n)) {
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

int InThreeSigm(int x, int *a, int *n) {
    double sigma;
    int result = 0;
    sigma = sqrt(((max(a, n) - min(a, n) + 1) * (max(a, n) - min(a, n) + 1) - 1) / 12.0);
    if (x <= mean(a, n) + 3 * sigma) {
        result = 1;
    }
    return result;
}

int DesiredNumber(int *a, int *n) {
    int result = 0;
    int counter = 0;
    for (int i = 0; i < *n; i++) {
        if (!(a[i] % 2) && a[i] >= mean(a, n) && InThreeSigm(a[i], a, n) && a[i] && !counter) {
            result = a[i];
            counter++;
        }
    }
    return result;
}

void output(int *a, int *n) { printf("%d", DesiredNumber(a, n)); }
