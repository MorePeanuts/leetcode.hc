class Solution {
public:
    int findMin(std::vector<int>& nums) {
        int left = 0;
        int right = static_cast<int>(nums.size()) - 1;
        while (left < right) {
            int mid = left + ((right - left) >> 1);
            if (nums[mid] > nums[right]) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return nums[left];
    }
};
