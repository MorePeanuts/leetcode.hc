function minPathSum(matrix) {
    const rows = matrix.length;
    const columns = matrix[0].length;
    const dp = [];
    dp[0] = matrix[0][0];
    for (let j = 1; j < columns; j++) {
        dp[j] = dp[j - 1] + matrix[0][j];
    }
    for (let i = 1; i < rows; i++) {
        dp[0] += matrix[i][0];
        for (let j = 1; j < columns; j++) {
            dp[j] = matrix[i][j] + (dp[j] < dp[j - 1] ? dp[j] : dp[j - 1]);
        }
    }
    return dp[columns - 1];
}
