#include "data_io.h"

#include <stdio.h>

void input(double *data, int n) {
    for (int i = 0; i < n; i++) {
        scanf("%lf", &data[i]);
    }
}

void output(double *data, int n) {
    for (int i = 0; i < n; i++) {
        printf("%.2lf", data[i]);
        if (i < n - 1) {
            printf(" ");
        }
    }
}

void sort(double *data, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (data[j] > data[j + 1]) {
                double temp = data[j];
                data[j] = data[j + 1];
                data[j + 1] = temp;
            }
        }
    }
}
