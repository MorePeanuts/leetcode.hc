class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        int m = static_cast<int>(mat.size());
        int n = static_cast<int>(mat[0].size());
        vector<vector<int>> prefix(m + 1, vector<int>(n + 1));
            vector<vector<int>> result(m, vector<int>(n));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                prefix[i + 1][j + 1] = mat[i][j] + prefix[i][j + 1] + prefix[i + 1][j] - prefix[i][j];
            }
        }
        for (int i = 0; i < m; i++) {
            int top = i > k ? i - k : 0;
            int bottom = i + k + 1 < m ? i + k + 1 : m;
            for (int j = 0; j < n; j++) {
                int left = j > k ? j - k : 0;
                int right = j + k + 1 < n ? j + k + 1 : n;
                result[i][j] = prefix[bottom][right] - prefix[top][right] - prefix[bottom][left] + prefix[top][left];
            }
        }
        return result;
    }
};
