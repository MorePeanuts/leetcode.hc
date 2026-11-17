#include <stdlib.h>

static void mark(char** board, int* stack, int* count, int cols, int row, int col) {
    if (board[row][col] != 'O') return;
    board[row][col] = '#';
    stack[(*count)++] = row * cols + col;
}

void solve(char** board, int boardSize, int* boardColSize) {
    int cols = boardColSize[0];
    int* stack = malloc((size_t)boardSize * cols * sizeof(*stack));
    int count = 0;
    for (int row = 0; row < boardSize; row++) {
        mark(board, stack, &count, cols, row, 0);
        mark(board, stack, &count, cols, row, cols - 1);
    }
    for (int col = 0; col < cols; col++) {
        mark(board, stack, &count, cols, 0, col);
        mark(board, stack, &count, cols, boardSize - 1, col);
    }
    while (count > 0) {
        int cell = stack[--count];
        int row = cell / cols;
        int col = cell % cols;
        if (row > 0) mark(board, stack, &count, cols, row - 1, col);
        if (row + 1 < boardSize) mark(board, stack, &count, cols, row + 1, col);
        if (col > 0) mark(board, stack, &count, cols, row, col - 1);
        if (col + 1 < cols) mark(board, stack, &count, cols, row, col + 1);
    }
    for (int row = 0; row < boardSize; row++)
        for (int col = 0; col < cols; col++)
            board[row][col] = board[row][col] == '#' ? 'O' : 'X';
    free(stack);
}
