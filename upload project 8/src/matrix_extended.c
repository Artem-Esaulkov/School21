#include <stdio.h>
#include <stdlib.h>

int input(int *n);
void OutputMatrix(int **data, int lines, int columns);
int InputMatrix(int **data, int lines, int columns);
void OutputMaxMin(int **data, int lines, int columns);
int MaxNumber(int **data, int n, int columns);
int MinNumber(int **data, int n, int lines);

int main() {
    int number, lines, columns;
    if (input(&number)) {
        printf("n/a");
    } else if (number < 1 || number > 4) {
        printf("n/a");
    } else if (input(&lines) || input(&columns)) {
        printf("n/a");
    } else if (number < 1 || columns < 1) {
        printf("n/a");
    } else if (number == 1) {
        int matrix[lines][columns];
        int *pointers[lines];
        for (int i = 0; i < lines; i++) {
            pointers[i] = matrix[i];
        }
        if (InputMatrix(pointers, lines, columns)) {
            printf("n/a");
        } else {
            OutputMatrix(pointers, lines, columns);
            OutputMaxMin(pointers, lines, columns);
        }
    } else if (number == 2) {
        int **data = (int **)malloc(lines * sizeof(int *) + lines * columns * sizeof(int));
        if (data == NULL) {
            printf("n/a");
        } else {
            int *ptr = (int *)(data + lines);
            for (int i = 0; i < lines; i++) {
                data[i] = ptr + columns * i;
            }
            if (InputMatrix(data, lines, columns)) {
                printf("n/a");
            } else {
                OutputMatrix(data, lines, columns);
                OutputMaxMin(data, lines, columns);
            }
            free(data);
        }
    } else if (number == 3) {
        int **data = (int **)malloc(lines * sizeof(int *));
        if (data == NULL) {
            printf("n/a");
        } else {
            for (int i = 0; i < lines; i++) {
                data[i] = malloc(columns * sizeof(int));
            }
            if (InputMatrix(data, lines, columns)) {
                printf("n/a");
            } else {
                OutputMatrix(data, lines, columns);
                OutputMaxMin(data, lines, columns);
            }
            for (int i = 0; i < lines; i++) {
                free(data[i]);
            }
            free(data);
        }
    } else if (number == 4) {
        int **data = (int **)malloc(lines * sizeof(int *));
        int *values = (int *)malloc(lines * columns * sizeof(int));
        for (int i = 0; i < lines; i++) {
            data[i] = values + columns * i;
        }
        if (InputMatrix(data, lines, columns)) {
            printf("n/a");
        } else {
            OutputMatrix(data, lines, columns);
            OutputMaxMin(data, lines, columns);
        }
        free(values);
        free(data);
    }
    return 0;
}

int input(int *n) {
    int result = 0;
    if (scanf("%d", n) != 1 || *n <= 0) {
        result = 1;
    }
    return result;
}

int InputMatrix(int **data, int lines, int columns) {
    int result = 0;
    for (int i = 0; i < lines; i++) {
        for (int j = 0; j < columns; j++) {
            if (scanf("%d", &data[i][j]) != 1) {
                result = 1;
            }
        }
    }
    return result;
}

int MaxNumber(int **data, int n, int columns) {
    int max = data[n][0];
    for (int i = 1; i < columns; i++) {
        if (data[n][i] > max) {
            max = data[n][i];
        }
    }
    return max;
}

int MinNumber(int **data, int n, int lines) {
    int min = data[0][n];
    for (int i = 0; i < lines; i++) {
        if (data[i][n] < min) {
            min = data[i][n];
        }
    }
    return min;
}

void OutputMatrix(int **data, int lines, int columns) {
    for (int i = 0; i < lines; i++) {
        for (int j = 0; j < columns; j++) {
            printf("%d", data[i][j]);
            if (j < columns - 1) {
                printf(" ");
            }
        }
        if (i <= lines - 1) {
            printf("\n");
        }
    }
}

void OutputMaxMin(int **data, int lines, int columns) {
    for (int i = 0; i < lines; i++) {
        if (i < lines - 1) {
            printf("%d ", MaxNumber(data, i, columns));
        } else {
            printf("%d\n", MaxNumber(data, i, columns));
        }
    }
    for (int i = 0; i < columns; i++) {
        if (i < columns - 1) {
            printf("%d ", MinNumber(data, i, lines));
        } else {
            printf("%d", MinNumber(data, i, lines));
        }
    }
}
