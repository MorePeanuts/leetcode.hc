class Solution {
    public int numSquares(int n) {
        int[] dp = new int[n + 1];
        dp[0] = 0;
        for (int total = 1; total <= n; total++) {
            dp[total] = total;
            for (int s = 1; s * s <= total; s++) {
                int candidate = dp[total - s * s] + 1;
                if (candidate < dp[total]) {
                    dp[total] = candidate;
                }
            }
        }
        return dp[n];
    }
}
