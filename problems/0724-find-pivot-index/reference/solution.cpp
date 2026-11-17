class Solution {
public:
    int pivotIndex(std::vector<int>& nums) {
        int right = 0;
        for (int i = 0; i < static_cast<int>(nums.size()); ++i) {
            right += nums[i];
        }
        int left = 0;
        for (int i = 0; i < static_cast<int>(nums.size()); ++i) {
            right -= nums[i];
            if (left == right) {
                return i;
            }
            left += nums[i];
        }
        return -1;
    }
};
