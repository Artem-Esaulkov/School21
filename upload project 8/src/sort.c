#include <stdio.h>
#include <stdlib.h>

int input(int *n);
void sort(int *a, int *n);
void output(int *a, int *n);

int main() {
    int n;
    int error_test = 0;
    if (input(&n) || n <= 0) {
        printf("n/a");
    } else {
        int *data = (int *)malloc(n * sizeof(int));
        for (int i = 0; i < n; i++) {
            if (scanf("%d", &data[i]) != 1) {
                error_test = 1;
            }
        }
        if (error_test) {
            printf("n/a");
            free(data);
        } else {
            sort(data, &n);
            output(data, &n);
            free(data);
        }
    }
    return 0;
}

int input(int *n) {
    int result = 0;
    if (scanf("%d", n) != 1) {
        result = 1;
    }
    return result;
}

void sort(int *a, int *n) {
    for (int i = 0; i < *n - 1; i++) {
        for (int j = 0; j < *n - 1 - i; j++) {
            if (a[j] > a[j + 1]) {
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}

void output(int *a, int *n) {
    for (int i = 0; i < *n; i++) {
        if (i != *n - 1) {
            printf("%d ", a[i]);
        } else {
            printf("%d", a[i]);
        }
    }
}
