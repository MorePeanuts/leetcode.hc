function numTrees(n) {
    const dp = [];
    dp[0] = 1;
    for (let nodes = 1; nodes <= n; nodes++) {
        dp[nodes] = 0;
        for (let left = 0; left < nodes; left++) {
            dp[nodes] += dp[left] * dp[nodes - 1 - left];
        }
    }
    return dp[n];
}
