#include <stdio.h>

int FibbonacciNumber(int number);

int main() {
    int number;
    if (scanf("%d", &number) == 1) {
        printf("%d", FibbonacciNumber(number));
        return 0;
    } else {
        printf("n/a");
        return 0;
    }
}

int FibbonacciNumber(int number) {
    int a = 1;
    int b = 1;
    int result = b;
    for (int i = 3; i <= number; i++) {
        result = a + b;
        a = b;
        b = result;
    }
    return result;
}
