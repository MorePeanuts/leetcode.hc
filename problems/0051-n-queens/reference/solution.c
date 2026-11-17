typedef struct {
    char*** boards;
    int* sizes;
    int count;
    int capacity;
} Results;

static void visit(int row, int n, int columns, int down, int up, int* placement, Results* result) {
    if (row == n) {
        if (result->count == result->capacity) {
            result->capacity = result->capacity ? result->capacity * 2 : 8;
            result->boards = realloc(result->boards, (size_t)result->capacity * sizeof(*result->boards));
            result->sizes = realloc(result->sizes, (size_t)result->capacity * sizeof(*result->sizes));
        }
        char** board = malloc((size_t)n * sizeof(*board));
        for (int i = 0; i < n; ++i) {
            board[i] = malloc((size_t)n + 1);
            memset(board[i], '.', (size_t)n);
            board[i][placement[i]] = 'Q';
            board[i][n] = 0;
        }
        result->boards[result->count] = board;
        result->sizes[result->count++] = n;
        return;
    }
    for (int col = 0; col < n; ++col) {
        int columnBit = 1 << col;
        int downBit = 1 << (row - col + n - 1);
        int upBit = 1 << (row + col);
        if ((columns & columnBit) || (down & downBit) || (up & upBit)) {
            continue;
        }
        placement[row] = col;
        visit(row + 1, n, columns | columnBit, down | downBit, up | upBit, placement, result);
    }
}

char*** solveNQueens(int n, int* returnSize, int** returnColumnSizes) {
    int placement[9];
    Results result = {0};
    visit(0, n, 0, 0, 0, placement, &result);
    *returnSize = result.count;
    *returnColumnSizes = result.sizes;
    return result.boards;
}
