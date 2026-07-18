#include <stdio.h>
#define NMAX 10

int input(int *buffer, int *length, int *step);
int ErrorTest(int *buffer, int *length, int *step);
void output(int *buffer, int *length);
void ArrayChange(int *buffer, int *length, int *step);

int main() {
    int length, step, buffer[NMAX];
    if (input(buffer, &length, &step)) {
        printf("n/a");
    } else {
        ArrayChange(buffer, &length, &step);
        output(buffer, &length);
    }
    return 0;
}

int input(int *buffer, int *length, int *step) {
    int result = 0;
    char c;
    if (scanf("%d%c", length, &c) != 1 && c != '\n') {
        result = 1;
    } else if (ErrorTest(buffer, length, step)) {
        result = 1;
    }
    return result;
}

int ErrorTest(int *buffer, int *length, int *step) {
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
        if (!result) {
            if (scanf("%d", step) != 1) {
                result = 1;
            }
        }
    }
    return result;
}

void ArrayChange(int *buffer, int *length, int *step) {
    int copy_buffer[NMAX];
    for (int i = 0; i < *length; i++) {
        copy_buffer[i] = buffer[i];
    }
    for (int i = 0; i < *length; i++) {
        if (*step >= 0) {
            if (i + *step < *length) {
                buffer[i] = copy_buffer[i + *step];
            } else {
                buffer[i] = copy_buffer[i + *step - *length];
            }
        } else {
            if (i + *step < 0) {
                buffer[i] = copy_buffer[i + *step + *length];
            } else {
                buffer[i] = copy_buffer[i + *step];
            }
        }
    }
}

void output(int *buffer, int *length) {
    for (int i = 0; i < *length; i++) {
        if (i == *length - 1) {
            printf("%d", buffer[i]);
        } else {
            printf("%d ", buffer[i]);
        }
    }
}
