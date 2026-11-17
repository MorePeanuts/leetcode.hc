class Solution {
    private boolean visit(char[][] board, int rows, int cols, String word, int length, int row, int col, int index) {
        if (row < 0 || row >= rows || col < 0 || col >= cols || board[row][col] != word.charAt(index)) {
            return false;
        }
        if (index + 1 == length) {
            return true;
        }
        char original = board[row][col];
        board[row][col] = '#';
        boolean found = visit(board, rows, cols, word, length, row + 1, col, index + 1)
            || visit(board, rows, cols, word, length, row - 1, col, index + 1)
            || visit(board, rows, cols, word, length, row, col + 1, index + 1)
            || visit(board, rows, cols, word, length, row, col - 1, index + 1);
        board[row][col] = original;
        return found;
    }

    public boolean exist(char[][] board, String word) {
        int rows = board.length;
        int cols = board[0].length;
        int length = word.length();

        for (int row = 0; row < rows; ++row) {
            for (int col = 0; col < cols; ++col) {
                if (visit(board, rows, cols, word, length, row, col, 0)) {
                    return true;
                }
            }
        }
        return false;
    }
}
