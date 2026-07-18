#include <stdio.h>

int IsPrimeNumber(int a);

int Multiples(int a);

int MaxNumber(int a, int b);

int main() {
    int number;
    if (scanf("%d", &number) != 1) {
        printf("n/a");
        return 0;
    } else {
        IsPrimeNumber(number) ? printf("%d", number) : printf("%d", Multiples(number));
        return 0;
    }
}

int IsPrimeNumber(int a) {
    int result = 1;
    int b = a;
    if (a < 0) b = a * (-1);
    for (int i = 2; i < b; i++) {
        for (int j = 2; j < b; j++) {
            if (i * j == b) {
                result = 0;
                break;
            }
        }
    }
    return result;
}

int Multiples(int a) {
    int max_multiple = 1;
    int b = a;
    if (a < 0) b = a * (-1);
    for (int i = 2; i < b; i++) {
        for (int j = 2; j < b; j++) {
            if (i * j == b) {
                if (IsPrimeNumber(i) && !IsPrimeNumber(j)) {
                    max_multiple = MaxNumber(i, max_multiple);
                    break;
                } else if (IsPrimeNumber(j) && !IsPrimeNumber(i)) {
                    max_multiple = MaxNumber(j, max_multiple);
                    break;
                } else if (IsPrimeNumber(i) && IsPrimeNumber(j)) {
                    int bonus_number = MaxNumber(i, j);
                    max_multiple = MaxNumber(bonus_number, max_multiple);
                    break;
                }
            }
        }
    }
    return max_multiple;
}

int MaxNumber(int a, int b) {
    int result = a;
    if (b > a) result = b;
    return result;
}
