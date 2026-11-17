class Solution {
    void visit(int row, int n, int columns, int down, int up, std::vector<int>& placement, std::vector<std::vector<std::string>>& result) {
        if (row == n) {
            std::vector<std::string> board(n, std::string(n, '.'));
            for (int i = 0; i < n; ++i) {
                board[i][placement[i]] = 'Q';
            }
            result.push_back(std::move(board));
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

public:
    std::vector<std::vector<std::string>> solveNQueens(int n) {
        std::vector<std::vector<std::string>> result;
        std::vector<int> placement(n);
        visit(0, n, 0, 0, 0, placement, result);
        return result;
    }
};
