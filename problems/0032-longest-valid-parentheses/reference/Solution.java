class Solution {
    public int longestValidParentheses(String s) {
        int n = s.length();
        int[] dp = new int[n];
        int best = 0;
        for (int i = 1; i < n; ++i) {
            if (s.charAt(i) == ')') {
                int opening = i - dp[i - 1] - 1;
                if (opening >= 0 && s.charAt(opening) == '(') {
                    dp[i] = dp[i - 1] + 2 + (opening > 0 ? dp[opening - 1] : 0);
                    if (dp[i] > best) {
                        best = dp[i];
                    }
                }
            }
        }
        return best;
    }
}
