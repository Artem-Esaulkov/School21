#include <stdio.h>

#define LEN 100

int input(int *buffer, int *len);
int parse_delimiter(char next_char, int *stop);
void output(int *buffer, int len);
int sum(int *buff1, int len1, int *buff2, int len2, int *result, int *result_len);
int sub(int *buff1, int len1, int *buff2, int len2, int *result, int *result_len);
void trim_leading_zeros(int *result, int *result_len);
int compare(int *buff1, int len1, int *buff2, int len2);

int main() {
    int buff1[LEN];
    int buff2[LEN];
    int len1 = 0;
    int len2 = 0;
    int success = 0;

    if (input(buff1, &len1) && input(buff2, &len2)) {
        success = 1;
    } else {
        printf("n/a");
    }

    if (success) {
        int res_sum[LEN + 1];
        int len_sum = 0;
        sum(buff1, len1, buff2, len2, res_sum, &len_sum);
        output(res_sum, len_sum);
        printf("\n");

        int res_sub[LEN];
        int len_sub = 0;
        if (sub(buff1, len1, buff2, len2, res_sub, &len_sub)) {
            output(res_sub, len_sub);
        } else {
            printf("n/a");
        }
    }

    return 0;
}

int input(int *buffer, int *len) {
    int count = 0;
    char next_char;
    int is_valid = 1;
    int stop = 0;

    while (count < LEN && is_valid && !stop) {
        int val;
        if (scanf("%d", &val) != 1 || val < 0 || val > 9) {
            is_valid = 0;
        } else {
            buffer[count] = val;
            count++;

            if (scanf("%c", &next_char) == 1) {
                is_valid = parse_delimiter(next_char, &stop);
            } else {
                stop = 1;
            }
        }
    }

    int result = 0;
    if (is_valid && count > 0) {
        *len = count;
        result = 1;
    }

    return result;
}

int parse_delimiter(char next_char, int *stop) {
    int is_valid = 1;
    if (next_char == ' ') {
        *stop = 0;
    } else if (next_char == '\n' || next_char == '\r') {
        *stop = 1;
    } else {
        is_valid = 0;
    }
    return is_valid;
}

void output(int *buffer, int len) {
    int start = 0;
    while (start < len - 1 && buffer[start] == 0) {
        start++;
    }
    for (int i = start; i < len; i++) {
        printf("%d", buffer[i]);
        if (i < len - 1) {
            printf(" ");
        }
    }
}

int sum(int *buff1, int len1, int *buff2, int len2, int *result, int *result_len) {
    int carry = 0;
    int i = len1 - 1;
    int j = len2 - 1;
    int k = (len1 > len2 ? len1 : len2);
    *result_len = k + 1;

    for (int idx = 0; idx < *result_len; idx++) {
        result[idx] = 0;
    }

    while (i >= 0 || j >= 0 || carry) {
        int d1 = (i >= 0) ? buff1[i] : 0;
        int d2 = (j >= 0) ? buff2[j] : 0;
        int current_sum = d1 + d2 + carry;

        result[k] = current_sum % 10;
        carry = current_sum / 10;

        i--;
        j--;
        k--;
    }

    return 1;
}

int compare(int *buff1, int len1, int *buff2, int len2) {
    int s1 = 0;
    int s2 = 0;
    while (s1 < len1 - 1 && buff1[s1] == 0) s1++;
    while (s2 < len2 - 1 && buff2[s2] == 0) s2++;

    int active_len1 = len1 - s1;
    int active_len2 = len2 - s2;
    int res = 0;

    if (active_len1 > active_len2) res = 1;
    if (active_len1 < active_len2) res = -1;

    while (active_len1 == active_len2 && s1 < len1 && s2 < len2 && res == 0) {
        if (buff1[s1] > buff2[s2]) res = 1;
        if (buff1[s1] < buff2[s2]) res = -1;
        s1++;
        s2++;
    }
    return res;
}

int sub(int *buff1, int len1, int *buff2, int len2, int *result, int *result_len) {
    int status = 0;

    if (compare(buff1, len1, buff2, len2) >= 0) {
        status = 1;
        int borrow = 0;
        int i = len1 - 1;
        int j = len2 - 1;
        int k = len1 - 1;
        *result_len = len1;

        while (i >= 0) {
            int d1 = buff1[i];
            int d2 = (j >= 0) ? buff2[j] : 0;
            int current_diff = d1 - d2 - borrow;

            if (current_diff < 0) {
                current_diff += 10;
                borrow = 1;
            } else {
                borrow = 0;
            }

            result[k] = current_diff;
            i--;
            j--;
            k--;
        }
        trim_leading_zeros(result, result_len);
    }

    return status;
}

void trim_leading_zeros(int *result, int *result_len) {
    int start = 0;
    while (start < *result_len - 1 && result[start] == 0) {
        start++;
    }
    if (start > 0) {
        for (int idx = 0; idx < *result_len - start; idx++) {
            result[idx] = result[idx + start];
        }
        *result_len -= start;
    }
}
