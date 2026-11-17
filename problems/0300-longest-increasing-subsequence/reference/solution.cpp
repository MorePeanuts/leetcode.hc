class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = static_cast<int>(nums.size());
        vector<int> dp(n);
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
};
