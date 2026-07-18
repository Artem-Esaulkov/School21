#include "data_stat.h"

double max(double *data, int n) {
    double max_number = data[0];
    for (int i = 1; i < n; i++) {
        if (data[i] > max_number) {
            max_number = data[i];
        }
    }
    return max_number;
}

double min(double *data, int n) {
    double min_number = data[0];
    for (int i = 1; i < n; i++) {
        if (data[i] < min_number) {
            min_number = data[i];
        }
    }
    return min_number;
}

double mean(double *data, int n) {
    double mean_number = (min(data, n) + max(data, n)) / 2.0;
    return mean_number;
}

double variance(double *data, int n) {
    double variance_number;
    variance_number = (max(data, n) - min(data, n)) * (max(data, n) - min(data, n)) / 12.0;
    return variance_number;
}
