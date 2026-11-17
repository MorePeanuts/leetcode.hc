class Solution {
public:
    int minSubArrayLen(int target, std::vector<int>& nums) {
        int left = 0;
        int sum = 0;
        int best = static_cast<int>(nums.size()) + 1;
        for (int right = 0; right < static_cast<int>(nums.size()); ++right) {
            sum += nums[right];
            while (sum >= target) {
                int size = right - left + 1;
                if (size < best) {
                    best = size;
                }
                sum -= nums[left++];
            }
        }
        return best > static_cast<int>(nums.size()) ? 0 : best;
    }
};
