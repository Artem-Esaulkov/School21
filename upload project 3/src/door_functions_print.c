#include <math.h>
#include <stdio.h>

void VerseraAnnesy();
void LemniskataBernulli(double x);
void SquareHyperbola(double x);

int main() {
    double pi = 3.14159265358979323846;
    double x = pi * (-1);
    VerseraAnnesy(x);
    LemniskataBernulli(x);
    SquareHyperbola(x);
    return 0;
}

void VerseraAnnesy() {
    int width = 42;
    int height = 21;
    double y;
    y = 1.0 / (1.0 + x * x);
    while (x <= width) {
        if (y == 1.0 / (1.0 + x * x)) {
            printf("*");
        } else {
            printf(" ");
        }
    }
    y = 1.0 / (1.0 + x * x);
}

double LemniskataBernulli(double x) {
    if (x > pow(2, 0.5) || x < pow(2, 0.5) * (-1.0)) {
        return 0.0;
    } else
        return pow(pow(4.0 * x * x + 1.0, 0.5) - x * x - 1.0, 0.5);
}

double SquareHyperbola(double x) {
    if (x) {
        return 1.0 / (x * x);
    } else
        return 0.0;
}
