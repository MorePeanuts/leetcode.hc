class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int rows = mat.size(), cols = mat[0].size();
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                if (mat[r][c] == 0) {
                    continue;
                }
                int best = rows + cols;
                if (r > 0) {
                    best = min(best, mat[r - 1][c] + 1);
                }
                if (c > 0) {
                    best = min(best, mat[r][c - 1] + 1);
                }
                mat[r][c] = best;
            }
        }
        for (int r = rows - 1; r >= 0; r--) {
            for (int c = cols - 1; c >= 0; c--) {
                if (r + 1 < rows) {
                    mat[r][c] = min(mat[r][c], mat[r + 1][c] + 1);
                }
                if (c + 1 < cols) {
                    mat[r][c] = min(mat[r][c], mat[r][c + 1] + 1);
                }
            }
        }
        return mat;
    }
};
