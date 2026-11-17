bool isInterleave(char* s1, char* s2, char* s3) {
    int m = (int)strlen(s1);
    int n = (int)strlen(s2);
    if (m + n != (int)strlen(s3)) {
        return false;
    }
    int* dp = calloc((size_t)(n + 1), sizeof(*dp));
    dp[0] = 1;
    for (int i = 0; i <= m; ++i) {
        for (int j = 0; j <= n; ++j) {
            if (i == 0 && j == 0) {
                continue;
            }
            bool fromS1 = i > 0 && dp[j] != 0 && s1[i - 1] == s3[i + j - 1];
            bool fromS2 = j > 0 && dp[j - 1] != 0 && s2[j - 1] == s3[i + j - 1];
            dp[j] = fromS1 || fromS2 ? 1 : 0;
        }
    }
    bool answer = dp[n] != 0;
    free(dp);
    return answer;
}
