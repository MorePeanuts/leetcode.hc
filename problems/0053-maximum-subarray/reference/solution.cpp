class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int current = nums[0];
        int best = current;
        for (int i = 1; i < static_cast<int>(nums.size()); i++) {
            current = current > 0 ? current + nums[i] : nums[i];
            if (current > best) best = current;
        }
        return best;
    }
};
