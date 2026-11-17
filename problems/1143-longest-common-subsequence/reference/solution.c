int longestCommonSubsequence(char *a, char *b) {
    int m = strlen(a);
    int n = strlen(b);
    int dp[n + 1];
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= m; i++) {
        int diagonal = 0;
        for (int j = 1; j <= n; j++) {
            int above = dp[j];
            if (a[i - 1] == b[j - 1]) {
                dp[j] = diagonal + 1;
            } else if (dp[j - 1] > above) {
                dp[j] = dp[j - 1];
            }
            diagonal = above;
        }
    }
    return dp[n];
}
