#include "s21_string.h"

int s21_strlen(const char *str) {
    int length = 0;
    for (length = 0; str[length] != '\0'; length++) {
    }
    return length;
}

char *s21_strcpy(char *destination, const char *source) {
    int i = 0;
    for (i = 0; source[i] != '\0'; i++) {
        destination[i] = source[i];
    }
    destination[i] = '\0';
    return destination;
}

char *s21_strcat(char *destination, const char *str1, const char *str2) {
    for (int i = 0; i < s21_strlen(str1); i++) {
        destination[i] = str1[i];
    }
    for (int i = 0; i < s21_strlen(str2); i++) {
        destination[s21_strlen(str1) - 1 + i] = str2[i];
    }
    return destination;
}

int s21_strchr(const char *str, char ch) {
    int result = 0;
    int counter = 0;
    for (int i = 0; i < s21_strlen(str) || !counter; i++) {
        if (ch == str[i]) {
            result = i;
            counter++;
        }
    }
    return result;
}
