class Solution {
public:
    std::vector<std::vector<int>> generateMatrix(int n) {
        std::vector<std::vector<int>> matrix(n, std::vector<int>(n));
        int row = 0;
        int col = 0;
        int dr = 0;
        int dc = 1;
        for (int value = 1; value <= n * n; ++value) {
            matrix[row][col] = value;
            int nr = row + dr;
            int nc = col + dc;
            if (nr < 0 || nr >= n || nc < 0 || nc >= n || matrix[nr][nc] != 0) {
                int oldDr = dr;
                dr = dc;
                dc = -oldDr;
            }
            row += dr;
            col += dc;
        }
        return matrix;
    }
};
