#include <stdio.h>

char board[3][3];  // 3x3 game board

void initializeBoard();
void displayBoard();
int checkWinner();
int isDraw();
void makeMove(int player);

void initializeBoard() {
    int i, j;
    for (i = 0; i < 3; i++)
        for (j = 0; j < 3; j++)
            board[i][j] = ' ';
}

void displayBoard() {
    printf("\n");
    printf(" %c | %c | %c \n", board[0][0], board[0][1], board[0][2]);
    printf("---|---|---\n");
    printf(" %c | %c | %c \n", board[1][0], board[1][1], board[1][2]);
    printf("---|---|---\n");
    printf(" %c | %c | %c \n", board[2][0], board[2][1], board[2][2]);
    printf("\n");
}

int checkWinner() {
    int i;

    // Check rows and columns
    for (i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] &&
            board[i][1] == board[i][2] &&
            board[i][0] != ' ')
            return 1;

        if (board[0][i] == board[1][i] &&
            board[1][i] == board[2][i] &&
            board[0][i] != ' ')
            return 1;
    }

    // Check diagonals
    if (board[0][0] == board[1][1] &&
        board[1][1] == board[2][2] &&
        board[0][0] != ' ')
        return 1;

    if (board[0][2] == board[1][1] &&
        board[1][1] == board[2][0] &&
        board[0][2] != ' ')
        return 1;

    return 0;
}

int isDraw() {
    int i, j;
    for (i = 0; i < 3; i++)
        for (j = 0; j < 3; j++)
            if (board[i][j] == ' ')
                return 0;  // still empty cells → not draw
    return 1; // all filled → draw
}

void makeMove(int player) {
    int row, col;
    char mark = (player == 1) ? 'X' : 'O';

    while (1) {
        printf("Player %d (%c), enter your move (row and column: 1-3 1-3): ", player, mark);
        scanf("%d %d", &row, &col);

        row--;
        col--;

        if (row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == ' ') {
            board[row][col] = mark;
            break;
        } else {
            printf("Invalid move! Try again.\n");
        }
    }
}

int main() {
    int player = 1;
    int winner = 0;

    initializeBoard();

    printf("=== TIC TAC TOE ===\n");
    printf("Player 1: X | Player 2: O\n");

    while (1) {
        displayBoard();
        makeMove(player);

        if (checkWinner()) {
            displayBoard();
            printf("Player %d wins!\n", player);
            break;
        }

        if (isDraw()) {
            displayBoard();
            printf("It's a draw!\n");
            break;
        }

        // switch player
        player = (player == 1) ? 2 : 1;
    }

    return 0;
}
