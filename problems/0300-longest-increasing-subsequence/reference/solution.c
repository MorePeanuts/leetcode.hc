int lengthOfLIS(int* nums, int numsSize) {
    int n = numsSize;
    int dp[2500]; // n <= 2500
    int best = 0;
    for (int i = 0; i < n; i++) {
        int length = 1;
        for (int j = 0; j < i; j++) {
            if (nums[j] < nums[i] && dp[j] + 1 > length) length = dp[j] + 1;
        }
        dp[i] = length;
        if (length > best) best = length;
    }
    return best;
}
