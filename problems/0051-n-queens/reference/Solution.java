import java.util.ArrayList;
import java.util.List;

class Solution {
    private void visit(int row, int n, int columns, int down, int up, int[] placement, List<List<String>> result) {
        if (row == n) {
            List<String> board = new ArrayList<>(n);
            for (int col : placement) {
                board.add(".".repeat(col) + "Q" + ".".repeat(n - col - 1));
            }
            result.add(board);
            return;
        }
        for (int col = 0; col < n; ++col) {
            int columnBit = 1 << col;
            int downBit = 1 << (row - col + n - 1);
            int upBit = 1 << (row + col);
            if ((columns & columnBit) != 0 || (down & downBit) != 0 || (up & upBit) != 0) {
                continue;
            }
            placement[row] = col;
            visit(row + 1, n, columns | columnBit, down | downBit, up | upBit, placement, result);
        }
    }

    public List<List<String>> solveNQueens(int n) {
        List<List<String>> result = new ArrayList<>();
        int[] placement = new int[n];
        visit(0, n, 0, 0, 0, placement, result);
        return result;
    }
}
