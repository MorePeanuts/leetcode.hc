function maxCoins(nums: number[]): number {
    let n = nums.length + 2;
    const values = new Int32Array(n);
    const dp = Array.from({length: n}, () => new Int32Array(n));
    values[0] = values[n - 1] = 1;
    for (let i = 1; i < n - 1; i++) values[i] = nums[i - 1];
    for (let left = n - 3; left >= 0; left--) {
        for (let right = left + 2; right < n; right++) {
            let boundary = values[left] * values[right];
            let best = 0;
            for (let last = left + 1; last < right; last++) {
                let coins = dp[left][last] + dp[last][right] + boundary * values[last];
                if (coins > best) best = coins;
            }
            dp[left][right] = best;
        }
    }
    return dp[0][n - 1];
}
