#include <stdio.h>
#include <stdlib.h>

int input(int* n);
int input_matrix(int** data, int lines, int columns);
void sum(int** matrix_first, int** matrix_second, int n, int m);
void mul(int** matrix_first, int n_first, int m_first, int** matrix_second, int m_second,
         int** matrix_result);
void transp(int** matrix, int n, int m);
void output(int** data, int lines, int columns);

int main() {
    int way = 0;
    int n_first = 0;
    int m_first = 0;
    int n_second = 0;
    int m_second = 0;
    int error_test = 0;
    int** data = NULL;
    int** matrix = NULL;
    int** matrix_result = NULL;

    if (input(&way) || input(&n_first) || input(&m_first) || n_first <= 0 || m_first <= 0 || way < 1 ||
        way > 3) {
        error_test = 1;
    }

    if (!error_test) {
        data = (int**)malloc(n_first * sizeof(int*) + n_first * m_first * sizeof(int));
        if (data == NULL) {
            error_test = 1;
        } else {
            int* ptr = (int*)(data + n_first);
            for (int i = 0; i < n_first; i++) {
                data[i] = ptr + m_first * i;
            }
            if (input_matrix(data, n_first, m_first)) {
                error_test = 1;
            }
        }
    }

    if (!error_test && way == 3) {
        transp(data, n_first, m_first);
    }

    if (!error_test && way != 3) {
        if (input(&n_second) || input(&m_second) || n_second <= 0 || m_second <= 0) {
            error_test = 1;
        }
        if (!error_test && ((way == 1 && (n_first != n_second || m_first != m_second)) ||
                            (way == 2 && m_first != n_second))) {
            error_test = 1;
        }
    }

    if (!error_test && way != 3) {
        matrix = (int**)malloc(n_second * sizeof(int*) + n_second * m_second * sizeof(int));
        if (matrix == NULL) {
            error_test = 1;
        } else {
            int* potr = (int*)(matrix + n_second);
            for (int i = 0; i < n_second; i++) {
                matrix[i] = potr + m_second * i;
            }
            if (input_matrix(matrix, n_second, m_second)) {
                error_test = 1;
            }
        }
    }

    if (!error_test && way == 1) {
        sum(data, matrix, n_first, m_first);
    }

    if (!error_test && way == 2) {
        matrix_result = (int**)malloc(n_first * sizeof(int*) + n_first * m_second * sizeof(int));
        if (matrix_result == NULL) {
            error_test = 1;
        } else {
            int* potr_res = (int*)(matrix_result + n_first);
            for (int i = 0; i < n_first; i++) {
                matrix_result[i] = potr_res + m_second * i;
            }
            mul(data, n_first, m_first, matrix, m_second, matrix_result);
            output(matrix_result, n_first, m_second);
        }
    }

    if (error_test) {
        printf("n/a");
    }

    if (data != NULL) {
        free(data);
        data = NULL;
    }
    if (matrix != NULL) {
        free(matrix);
        matrix = NULL;
    }
    if (matrix_result != NULL) {
        free(matrix_result);
        matrix_result = NULL;
    }

    return error_test;
}

int input(int* n) {
    int res = 0;
    if (scanf("%d", n) != 1) {
        res = 1;
    }
    return res;
}

int input_matrix(int** data, int lines, int columns) {
    int res = 0;
    for (int i = 0; i < lines && !res; i++) {
        for (int j = 0; j < columns && !res; j++) {
            if (scanf("%d", &data[i][j]) != 1) {
                res = 1;
            }
        }
    }
    return res;
}

void output(int** data, int lines, int columns) {
    for (int i = 0; i < lines; i++) {
        for (int j = 0; j < columns; j++) {
            printf("%d", data[i][j]);
            if (j < columns - 1) {
                printf(" ");
            }
        }
        if (i != lines - 1) {
            printf("\n");
        }
    }
}

void sum(int** matrix_first, int** matrix_second, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d", matrix_first[i][j] + matrix_second[i][j]);
            if (j < m - 1) {
                printf(" ");
            }
        }
        if (i != n - 1) {
            printf("\n");
        }
    }
}

void mul(int** matrix_first, int n_first, int m_first, int** matrix_second, int m_second,
         int** matrix_result) {
    for (int i = 0; i < n_first; i++) {
        for (int j = 0; j < m_second; j++) {
            matrix_result[i][j] = 0;
            for (int k = 0; k < m_first; k++) {
                matrix_result[i][j] += matrix_first[i][k] * matrix_second[k][j];
            }
        }
    }
}

void transp(int** matrix, int n, int m) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d", matrix[j][i]);
            if (j < n - 1) {
                printf(" ");
            }
        }
        if (i != n - 1) {
            printf("\n");
        }
    }
}
