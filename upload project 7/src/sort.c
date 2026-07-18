#include <stdio.h>
#define NMAX 10

int input(int *a);
void sort(int *a);
void output(const int *a);

int main() {
    int data[NMAX];
    if (input(data) == 1) {
        printf("n/a");
    } else {
        sort(data);
        output(data);
    }
    return 0;
}

int input(int *a) {
    int result = 0;
    for (int *p = a; p - a < 10; p++) {
        if (scanf("%d", p) != 1) {
            result = 1;
        }
    }
    return result;
}

void sort(int *a) {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9 - i; j++) {
            if (a[j] > a[j + 1]) {
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}

void output(const int *a) {
    for (int i = 0; i < 10; i++) {
        if (i != 9) {
            printf("%d ", a[i]);
        } else {
            printf("%d", a[i]);
        }
    }
}
