class Solution {
public:
    void rotate(std::vector<std::vector<int>>& matrix) {
        int n = static_cast<int>(matrix.size());
        for (int row = 0; row < n; ++row) {
            for (int col = row + 1; col < n; ++col) {
                int temp = matrix[row][col];
                matrix[row][col] = matrix[col][row];
                matrix[col][row] = temp;
            }
        }
        for (int row = 0; row < n; ++row) {
            for (int left = 0, right = n - 1; left < right; ++left, --right) {
                int temp = matrix[row][left];
                matrix[row][left] = matrix[row][right];
                matrix[row][right] = temp;
            }
        }
    }
};
