class Solution {
    public int coinChange(int[] coins, int amount) {
        int n = coins.length;
        int impossible = amount + 1;
        int[] dp = new int[amount + 1];
        dp[0] = 0;
        for (int x = 1; x <= amount; x++) {
            dp[x] = impossible;
            for (int i = 0; i < n; i++) {
                int coin = coins[i];
                if (coin <= x && dp[x - coin] + 1 < dp[x]) {
                    dp[x] = dp[x - coin] + 1;
                }
            }
        }
        return dp[amount] == impossible ? -1 : dp[amount];
    }
}
