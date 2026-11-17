class Solution {
public:
    int search(std::vector<int>& nums, int target) {
        int left = 0;
        int right = static_cast<int>(nums.size());
        while (left < right) {
            int mid = left + ((right - left) >> 1);
            if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return left < static_cast<int>(nums.size()) && nums[left] == target ? left : -1;
    }
};
