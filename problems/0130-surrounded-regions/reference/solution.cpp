#include <vector>

class Solution {
public:
    void solve(std::vector<std::vector<char>>& board) {
        int rows = static_cast<int>(board.size());
        int cols = static_cast<int>(board[0].size());
        std::vector<int> stack;
        auto mark = [&](int row, int col) {
            if (board[row][col] != 'O') return;
            board[row][col] = '#';
            stack.push_back(row * cols + col);
        };

        for (int row = 0; row < rows; row++) {
            mark(row, 0);
            mark(row, cols - 1);
        }
        for (int col = 0; col < cols; col++) {
            mark(0, col);
            mark(rows - 1, col);
        }
        while (!stack.empty()) {
            int cell = stack.back();
            stack.pop_back();
            int row = cell / cols;
            int col = cell % cols;
            if (row > 0) mark(row - 1, col);
            if (row + 1 < rows) mark(row + 1, col);
            if (col > 0) mark(row, col - 1);
            if (col + 1 < cols) mark(row, col + 1);
        }
        for (auto& row : board)
            for (auto& cell : row) cell = cell == '#' ? 'O' : 'X';
    }
};
