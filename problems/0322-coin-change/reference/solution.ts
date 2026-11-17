function coinChange(coins: number[], amount: number): number {
    const n = coins.length;
    let impossible = amount + 1;
    const dp: number[] = [];
    dp[0] = 0;
    for (let x = 1; x <= amount; x++) {
        dp[x] = impossible;
        for (let i = 0; i < n; i++) {
            let coin = coins[i];
            if (coin <= x && dp[x - coin] + 1 < dp[x]) {
                dp[x] = dp[x - coin] + 1;
            }
        }
    }
    return dp[amount] === impossible ? -1 : dp[amount];
}
