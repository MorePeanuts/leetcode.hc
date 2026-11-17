class Solution {
    public int maxCoins(int[] nums) {
        int n = nums.length + 2;
        int[] values = new int[n];
        int[][] dp = new int[n][n];
        values[0] = values[n - 1] = 1;
        for (int i = 1; i < n - 1; i++) values[i] = nums[i - 1];
        for (int left = n - 3; left >= 0; left--) {
            for (int right = left + 2; right < n; right++) {
                int boundary = values[left] * values[right];
                int best = 0;
                for (int last = left + 1; last < right; last++) {
                    int coins = dp[left][last] + dp[last][right] + boundary * values[last];
                    if (coins > best) best = coins;
                }
                dp[left][right] = best;
            }
        }
        return dp[0][n - 1];
    }
}
