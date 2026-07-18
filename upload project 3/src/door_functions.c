#include <math.h>
#include <stdio.h>

double VerseraAnnesy(double x);
double LemniskataBernulli(double x);
double SquareHyperbola(double x);

int main() {
    double pi = 3.14159265358979323846;
    double x = pi * (-1);
    for (int i = 1; i <= 42; i++) {
        x = pi * (-1) + ((2.0 * pi) / 41.0) * (i - 1.0);
        printf("%.7f|%.7f|", x, VerseraAnnesy(x));
        if (LemniskataBernulli(x))
            printf("%.7f|", LemniskataBernulli(x));
        else
            printf("-|");
        if (SquareHyperbola(x) && i < 42)
            printf("%.7f\n", SquareHyperbola(x));
        else if (SquareHyperbola(x) && i == 42)
            printf("%.7f", SquareHyperbola(x));
        else
            printf("-\n");
    }
    return 0;
}

double VerseraAnnesy(double x) { return 1.0 / (1.0 + x * x); }

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
