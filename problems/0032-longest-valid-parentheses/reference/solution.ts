function longestValidParentheses(s: string): number {
    let n = s.length;
    const dp = new Int32Array(n);
    let best = 0;
    for (let i = 1; i < n; ++i) {
        if (s[i] === ")") {
            let opening = i - dp[i - 1] - 1;
            if (opening >= 0 && s[opening] === "(") {
                dp[i] = dp[i - 1] + 2 + (opening > 0 ? dp[opening - 1] : 0);
                if (dp[i] > best) {
                    best = dp[i];
                }
            }
        }
    }
    return best;
}
