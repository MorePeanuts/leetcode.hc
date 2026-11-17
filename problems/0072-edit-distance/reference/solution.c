int minDistance(char* word1, char* word2) {
    int m = (int)strlen(word1);
    int n = (int)strlen(word2);
    int* dp = calloc((size_t)(n + 1), sizeof(*dp));
    for (int j = 0; j <= n; ++j) {
        dp[j] = j;
    }
    for (int i = 1; i <= m; ++i) {
        int diagonal = dp[0];
        dp[0] = i;
        for (int j = 1; j <= n; ++j) {
            int above = dp[j];
            if (word1[i - 1] == word2[j - 1]) {
                dp[j] = diagonal;
            } else {
                int best = dp[j - 1] < above ? dp[j - 1] : above;
                dp[j] = (best < diagonal ? best : diagonal) + 1;
            }
            diagonal = above;
        }
    }
    int answer = dp[n];
    free(dp);
    return answer;
}
