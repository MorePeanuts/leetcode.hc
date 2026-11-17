int longestValidParentheses(char* s) {
    int n = (int)strlen(s);
    int* dp = calloc((size_t)(n), sizeof(*dp));
    int best = 0;
    for (int i = 1; i < n; ++i) {
        if (s[i] == ')') {
            int opening = i - dp[i - 1] - 1;
            if (opening >= 0 && s[opening] == '(') {
                dp[i] = dp[i - 1] + 2 + (opening > 0 ? dp[opening - 1] : 0);
                if (dp[i] > best) {
                    best = dp[i];
                }
            }
        }
    }
    free(dp);
    return best;
}
