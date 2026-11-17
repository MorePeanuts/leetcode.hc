function minDistance(word1, word2) {
    let m = word1.length;
    let n = word2.length;
    const dp = new Int32Array(n + 1);
    for (let j = 0; j <= n; ++j) {
        dp[j] = j;
    }
    for (let i = 1; i <= m; ++i) {
        let diagonal = dp[0];
        dp[0] = i;
        for (let j = 1; j <= n; ++j) {
            let above = dp[j];
            if (word1[i - 1] === word2[j - 1]) {
                dp[j] = diagonal;
            } else {
                let best = dp[j - 1] < above ? dp[j - 1] : above;
                dp[j] = (best < diagonal ? best : diagonal) + 1;
            }
            diagonal = above;
        }
    }
    let answer = dp[n];
    return answer;
}
