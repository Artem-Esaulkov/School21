#include <stdio.h>

void Coding();
void Decoding();
void DecToHex(int n);

int main() {
    int work_param;
    scanf("%d", &work_param);
    if (work_param == 0)
        Coding();
    else if (work_param == 1)
        Decoding();
    else
        printf("n/a");
    return 0;
}

void Coding() {
    char c;
    int isTrue = 1;
    int counter = 1;
    while (isTrue) {
        c = getchar();
        if (c == '\n' && counter == 1) {
            counter = 2;
            continue;
        }
        if (c == '\n' && counter == 2) break;
        if (c == ' ') {
            printf(" ");
            continue;
        }
        printf("%02X", c);
    }
}

void Decoding() {
    int current_number = 0;
    char c, symbol;
    while (scanf("%x", &current_number) == 1) {
        symbol = (char)current_number;
        printf("%c", symbol);
        c = getchar();
        if (c == '\n') {
            break;
        } else
            printf(" ");
    }
}

void DecToHex(int n) {
    if (n == 0) return;

    int remainder = n % 16;
    DecToHex(n / 16);

    if (remainder < 10) {
        printf("%d", remainder);
    } else {
        printf("%c", remainder - 10 + 'A');
    }
}
