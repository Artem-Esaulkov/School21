#include <stdio.h>

int ballX = 40;
int ballY = 12;

int player1Y, player2Y = 0;
int player1Score, player2Score = 0;

int enabled = 1;

char getInput() {
    char input;
    scanf("%c", &input);
    return input;
}

void update() {
    char input = getInput();
    switch (input) {
        case '0':
            enabled = 0;
            break;
        case 'A':
        case 'a':
            // Player 1 up
            if (player1Y > 0) {
                player1Y -= 1;
            }
            break;
        case 'Z':
        case 'z':
            // Player 1 down
            if (player1Y < 22) {
                player1Y += 1;
            }
            break;
        case 'K':
        case 'k':
            // Player 2 up
            if (player2Y > 0) {
                player2Y -= 1;
            }
            break;
        case 'M':
        case 'm':
            // Player 2 down
            if (player2Y < 22) {
                player2Y += 1;
            }
            break;
        default:
            break;
    }
}

void clearScreen() {
    printf("\033[H\033[2J");
    fflush(stdout); 
}

void drawScreen() {
    clearScreen();
    for (int y = 0; y < 25; y++) {
        for (int x = 0; x < 80; x++) {
            if (x == 0 && y >= player1Y && y <= player1Y + 2) {
                printf("|");
            } else if (x == 79 && y >= player2Y && y <= player2Y + 2) {
                printf("|");
            } else if (x == ballX && y == ballY) {
                printf("*");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

int main(void) {
    while (enabled) {
        drawScreen();
        update();
    }
}