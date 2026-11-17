function lengthOfLIS(nums) {
    let n = nums.length;
    const dp = new Int32Array(n);
    let best = 0;
    for (let i = 0; i < n; i++) {
        let length = 1;
        for (let j = 0; j < i; j++) {
            if (nums[j] < nums[i] && dp[j] + 1 > length) length = dp[j] + 1;
        }
        dp[i] = length;
        if (length > best) best = length;
    }
    return best;
}
