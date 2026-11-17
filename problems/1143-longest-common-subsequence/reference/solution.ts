function longestCommonSubsequence(a: string, b: string): number {
    const m = a.length;
    const n = b.length;
    const dp = new Int32Array(n + 1);
    for (let i = 1; i <= m; i++) {
        let diagonal = 0;
        for (let j = 1; j <= n; j++) {
            let above = dp[j];
            if (a[i - 1] === b[j - 1]) {
                dp[j] = diagonal + 1;
            } else if (dp[j - 1] > above) {
                dp[j] = dp[j - 1];
            }
            diagonal = above;
        }
    }
    return dp[n];
}
