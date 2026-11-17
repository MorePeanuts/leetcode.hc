function isInterleave(s1, s2, s3) {
    let m = s1.length;
    let n = s2.length;
    if (m + n !== s3.length) {
        return false;
    }
    const dp = new Int32Array(n + 1);
    dp[0] = 1;
    for (let i = 0; i <= m; ++i) {
        for (let j = 0; j <= n; ++j) {
            if (i === 0 && j === 0) {
                continue;
            }
            let fromS1 = i > 0 && dp[j] !== 0 && s1[i - 1] === s3[i + j - 1];
            let fromS2 = j > 0 && dp[j - 1] !== 0 && s2[j - 1] === s3[i + j - 1];
            dp[j] = fromS1 || fromS2 ? 1 : 0;
        }
    }
    let answer = dp[n] !== 0;
    return answer;
}
