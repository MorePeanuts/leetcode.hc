static bool visit(char** board, int rows, int cols, const char* word, int length, int row, int col, int index) {
    if (row < 0 || row >= rows || col < 0 || col >= cols || board[row][col] != word[index]) {
        return false;
    }
    if (index + 1 == length) {
        return true;
    }
    char original = board[row][col];
    board[row][col] = '#';
    bool found = visit(board, rows, cols, word, length, row + 1, col, index + 1)
        || visit(board, rows, cols, word, length, row - 1, col, index + 1)
        || visit(board, rows, cols, word, length, row, col + 1, index + 1)
        || visit(board, rows, cols, word, length, row, col - 1, index + 1);
    board[row][col] = original;
    return found;
}

bool exist(char** board, int boardSize, int* boardColSize, char* word) {
    int rows = boardSize;
    int cols = boardColSize[0];
    int length = (int)strlen(word);

    for (int row = 0; row < rows; ++row) {
        for (int col = 0; col < cols; ++col) {
            if (visit(board, rows, cols, word, length, row, col, 0)) {
                return true;
            }
        }
    }
    return false;
}
