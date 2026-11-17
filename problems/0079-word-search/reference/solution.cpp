class Solution {
    bool visit(std::vector<std::vector<char>>& board, int rows, int cols, const std::string& word, int length, int row, int col, int index) {
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

public:
    bool exist(std::vector<std::vector<char>>& board, std::string word) {
        int rows = static_cast<int>(board.size());
        int cols = static_cast<int>(board[0].size());
        int length = static_cast<int>(word.size());

        for (int row = 0; row < rows; ++row) {
            for (int col = 0; col < cols; ++col) {
                if (visit(board, rows, cols, word, length, row, col, 0)) {
                    return true;
                }
            }
        }
        return false;
    }
};
