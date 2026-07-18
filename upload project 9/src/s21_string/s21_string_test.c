#include "s21_string.h"

#include <stdio.h>
#include <stdlib.h>

void s21_strlen_test(const char *input, int expected);
void s21_strcmp(const char *str1, const char *str2);

int main() {
    printf("Тестирование функции длины строки: \n");
    s21_strlen_test("hello", 5);
    printf("\n");
    s21_strlen_test("empty", 14);
    printf("\n");
    s21_strlen_test("hello world", 10);
    printf("\n");
    printf("Тестирование функции сравнения строк: \n");
    s21_strcmp("hello", "hello");
    printf("\n");
    s21_strcmp("hello", "world");
    printf("\n");
    s21_strcmp("hello", "hello!");
    return 0;
}

void s21_strlen_test(const char *input, int expected) {
    int output = s21_strlen(input);
    printf("%s\n", input);
    printf("%d\n", expected);
    if (output == expected) {
        printf("Результат: SUCCESS");
    } else {
        printf("Результат: FAIL");
    }
}

void s21_strcmp(const char *str1, const char *str2) {
    int result = 1;
    int max_length = s21_strlen(str1);
    if (s21_strlen(str2) > max_length) {
        max_length = s21_strlen(str2);
    }
    printf("%s\n", str1);
    printf("%s\n", str2);
    for (int i = 0; i < max_length; i++) {
        if (str1[i] != str2[i]) {
            result = 0;
        }
    }
    if (result) {
        printf("Результат: SUCCESS");
    } else {
        printf("Результат: FAIL");
    }
}
