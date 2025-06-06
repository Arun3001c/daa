#include <stdio.h>
#include <stdbool.h>
#define MAX 10
int board[MAX][MAX];
int N;
void printBoard() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (board[i][j] == 1)
                printf("Q ");
            else
                printf(". ");
        }
        printf("\n");
    }
}
bool isSafe(int row, int col) {
    for (int i = 0; i < row; i++) {
        if (board[i][col] == 1)
            return false;
    }
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 1)
            return false;
    }
    for (int i = row, j = col; i >= 0 && j < N; i--, j++) {
        if (board[i][j] == 1)
            return false;
    }

    return true;
}
bool solveNQueens(int row) {
    if (row >= N) {
        return true;
    }
    for (int col = 0; col < N; col++) {
        if (isSafe(row, col)) {
            board[row][col] = 1;
            if (solveNQueens(row + 1)) {
                return true;
            }
            board[row][col] = 0;
        }
    }
    return false;
}

int main() {
    printf("Enter the size of the chessboard (N): ");
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            board[i][j] = 0;
        }
    }
    if (solveNQueens(0)) {
        printf("Solution found:\n");
        printBoard();
    } else {
        printf("No solution exists for %d queens.\n", N);
    }

    return 0;
}
