class Solution {
    public int[][] matrixBlockSum(int[][] mat, int k) {
        int m = mat.length;
        int n = mat[0].length;
        int[][] prefix = new int[m + 1][n + 1];
            int[][] result = new int[m][n];
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
}
