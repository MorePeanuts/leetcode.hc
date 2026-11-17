class Solution {
    public boolean isInterleave(String s1, String s2, String s3) {
        int m = s1.length();
        int n = s2.length();
        if (m + n != s3.length()) {
            return false;
        }
        int[] dp = new int[n + 1];
        dp[0] = 1;
        for (int i = 0; i <= m; ++i) {
            for (int j = 0; j <= n; ++j) {
                if (i == 0 && j == 0) {
                    continue;
                }
                boolean fromS1 = i > 0 && dp[j] != 0 && s1.charAt(i - 1) == s3.charAt(i + j - 1);
                boolean fromS2 = j > 0 && dp[j - 1] != 0 && s2.charAt(j - 1) == s3.charAt(i + j - 1);
                dp[j] = fromS1 || fromS2 ? 1 : 0;
            }
        }
        boolean answer = dp[n] != 0;
        return answer;
    }
}
