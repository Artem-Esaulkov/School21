#include <stdio.h>
#define NMAX 10

int input(int *buffer, int *length);
int ErrorTest(int *buffer, int *length);
void output(int *buffer, int *length);
int sum_numbers(int *buffer, int *length);
void find_numbers(int *buffer, int *length, int *number, int *numbers);

int main() {
    int length, number, buffer[NMAX], numbers[NMAX];
    if (input(buffer, &length)) {
        printf("n/a");
    } else if (!sum_numbers(buffer, &length)) {
        printf("n/a");
    } else {
        output(buffer, &length);
        find_numbers(buffer, &length, &number, numbers);
    }
    return 0;
}

int input(int *buffer, int *length) {
    int result = 0;
    char c;
    if (scanf("%d%c", length, &c) != 1 && c != '\n') {
        result = 1;
    } else if (ErrorTest(buffer, length)) {
        result = 1;
    }
    return result;
}

int ErrorTest(int *buffer, int *length) {
    int result = 0;
    int counter = 0;
    if (*length <= 0 || *length > NMAX) {
        result = 1;
    } else {
        for (int *p = buffer; p - buffer < *length; p++) {
            if (scanf("%d", p) == 1) {
                counter++;
            } else {
                result = 1;
            }
        }
        if (counter < *length) {
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

int sum_numbers(int *buffer, int *length) {
    int sum = 0;
    for (int i = 0; i < *length; i++) {
        if (buffer[i] % 2 == 0 && buffer[i]) {
            sum = sum + buffer[i];
        }
    }
    return sum;
}

void find_numbers(int *buffer, int *length, int *number, int *numbers) {
    *number = sum_numbers(buffer, length);
    int counter = 0;
    for (int i = 0; i < *length; i++) {
        if (*number != 0 && buffer[i] != 0 && *number % buffer[i] == 0) {
            numbers[counter] = buffer[i];
            counter++;
        }
    }
    if (!counter) {
        printf("n/a");
    }
    for (int i = 0; i < counter; i++) {
        i == counter - 1 ? printf("%d", numbers[i]) : printf("%d ", numbers[i]);
    }
}

void output(int *buffer, int *length) { printf("%d\n", sum_numbers(buffer, length)); }
