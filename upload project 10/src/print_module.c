#include "print_module.h"

#include <stdio.h>
#include <time.h>

void print_log(char (*print)(char), char* message) {
    time_t raw_time;
    struct tm* time_info;
    time(&raw_time);
    time_info = localtime(&raw_time);

    char time_str[9];
    strftime(time_str, sizeof(time_str), "%H:%M:%S", time_info);

    char prefix[] = "[LOG] ";
    for (int i = 0; prefix[i] != '\0'; i++) {
        print(prefix[i]);
    }

    for (int i = 0; time_str[i] != '\0'; i++) {
        print(time_str[i]);
    }

    print(' ');

    for (int i = 0; message[i] != '\0'; i++) {
        print(message[i]);
    }
}

char print_char(char ch) { return (char)putchar(ch); }
