import java.util.ArrayDeque;

class Solution {
    private void mark(char[][] board, ArrayDeque<Integer> stack, int row, int col) {
        if (board[row][col] != 'O') return;
        board[row][col] = '#';
        stack.push(row * board[0].length + col);
    }

    public void solve(char[][] board) {
        int rows = board.length;
        int cols = board[0].length;
        ArrayDeque<Integer> stack = new ArrayDeque<>();
        for (int row = 0; row < rows; row++) {
            mark(board, stack, row, 0);
            mark(board, stack, row, cols - 1);
        }
        for (int col = 0; col < cols; col++) {
            mark(board, stack, 0, col);
            mark(board, stack, rows - 1, col);
        }
        while (!stack.isEmpty()) {
            int cell = stack.pop();
            int row = cell / cols;
            int col = cell % cols;
            if (row > 0) mark(board, stack, row - 1, col);
            if (row + 1 < rows) mark(board, stack, row + 1, col);
            if (col > 0) mark(board, stack, row, col - 1);
            if (col + 1 < cols) mark(board, stack, row, col + 1);
        }
        for (char[] row : board)
            for (int col = 0; col < cols; col++)
                row[col] = row[col] == '#' ? 'O' : 'X';
    }
}
