#include <stdio.h>

#define N 15
#define M 13

void transform(int *buf, int **matr, int n, int m);
void make_picture(int **picture, int n, int m);
void reset_picture(int **picture, int n, int m);
void print_picture(int **picture, int n, int m);
void draw_frames(int **picture, int n, int m, const int *fw, const int *fh);
void draw_sun(int **picture, const int sd[6][5]);
void draw_foliage(int **picture, const int *tf);
void draw_trunk(int **picture, const int *tt);

int main() {
    int picture_data[N][M];
    int *picture[N];

    transform((int *)picture_data, picture, N, M);
    make_picture(picture, N, M);
    print_picture(picture, N, M);

    return 0;
}

void make_picture(int **picture, int n, int m) {
    int frame_w[] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
    int frame_h[] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
    int tree_trunk[] = {7, 7, 7, 7};
    int tree_foliage[] = {3, 3, 3, 3};
    int sun_data[6][5] = {{0, 6, 6, 6, 6}, {0, 0, 6, 6, 6}, {0, 0, 6, 6, 6},
                          {0, 6, 0, 0, 6}, {0, 0, 0, 0, 0}, {0, 0, 0, 0, 0}};

    reset_picture(picture, n, m);
    draw_frames(picture, n, m, frame_w, frame_h);
    draw_sun(picture, sun_data);
    draw_foliage(picture, tree_foliage);
    draw_trunk(picture, tree_trunk);
}

void draw_frames(int **picture, int n, int m, const int *fw, const int *fh) {
    for (int j = 0; j < m; j++) {
        picture[0][j] = fw[j];
        picture[7][j] = fw[j];
        picture[n - 1][j] = fw[j];
    }
    for (int i = 0; i < n; i++) {
        picture[i][0] = fh[i];
        picture[i][6] = fh[i];
        picture[i][m - 1] = fh[i];
    }
}

void draw_sun(int **picture, const int sd[6][5]) {
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 5; j++) {
            if (sd[i][j] != 0) {
                picture[i + 1][j + 7] = sd[i][j];
            }
        }
    }
}

void draw_foliage(int **picture, const int *tf) {
    picture[2][3] = tf[0];
    picture[2][4] = tf[1];
    for (int j = 2; j <= 5; j++) {
        picture[3][j] = tf[j - 2];
        picture[4][j] = tf[j - 2];
    }
    picture[5][3] = tf[2];
    picture[5][4] = tf[3];
}

void draw_trunk(int **picture, const int *tt) {
    picture[6][3] = tt[0];
    picture[6][4] = tt[1];
    picture[8][3] = tt[0];
    picture[8][4] = tt[1];
    picture[9][3] = tt[2];
    picture[9][4] = tt[3];
    for (int j = 2; j <= 5; j++) {
        picture[10][j] = tt[j - 2];
    }
}

void reset_picture(int **picture, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            picture[i][j] = 0;
        }
    }
}

void transform(int *buf, int **matr, int n, int m) {
    for (int i = 0; i < n; i++) {
        matr[i] = buf + i * m;
    }
}

void print_picture(int **picture, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d", picture[i][j]);
            if (j < m - 1) {
                printf(" ");
            }
        }
        if (i != n - 1) {
            printf("\n");
        }
    }
}
