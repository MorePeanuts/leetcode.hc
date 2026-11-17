int numTrees(int n) {
    int dp[n + 1];
    dp[0] = 1;
    for (int nodes = 1; nodes <= n; nodes++) {
        dp[nodes] = 0;
        for (int left = 0; left < nodes; left++) {
            dp[nodes] += dp[left] * dp[nodes - 1 - left];
        }
    }
    return dp[n];
}
