class Solution {
public:
    int coinChange(vector<int> &coins, int amount) {
        int n = coins.size();
        int impossible = amount + 1;
        vector<int> dp(amount + 1);
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
};
