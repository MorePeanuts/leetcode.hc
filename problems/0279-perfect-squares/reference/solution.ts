function numSquares(n: number): number {
    const dp: number[] = [];
    dp[0] = 0;
    for (let total = 1; total <= n; total++) {
        dp[total] = total;
        for (let s = 1; s * s <= total; s++) {
            let candidate = dp[total - s * s] + 1;
            if (candidate < dp[total]) {
                dp[total] = candidate;
            }
        }
    }
    return dp[n];
}
