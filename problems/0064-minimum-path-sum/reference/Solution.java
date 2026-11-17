class Solution {
    public int minPathSum(int[][] matrix) {
        int rows = matrix.length;
        int columns = matrix[0].length;
        int[] dp = new int[columns];
        dp[0] = matrix[0][0];
        for (int j = 1; j < columns; j++) {
            dp[j] = dp[j - 1] + matrix[0][j];
        }
        for (int i = 1; i < rows; i++) {
            dp[0] += matrix[i][0];
            for (int j = 1; j < columns; j++) {
                dp[j] = matrix[i][j] + (dp[j] < dp[j - 1] ? dp[j] : dp[j - 1]);
            }
        }
        return dp[columns - 1];
    }
}
