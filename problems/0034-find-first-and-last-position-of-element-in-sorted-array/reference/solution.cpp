class Solution {
public:
    vector<int> searchRange(vector<int> &nums, int target) {
        int n = nums.size();
        int low = 0;
        int high = n;
        while (low < high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] < target) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }
        int first = -1;
        int last = -1;
        if (low < n && nums[low] == target) {
            first = low;
            high = n;
            while (low < high) {
                int mid = low + (high - low) / 2;
                if (nums[mid] <= target) {
                    low = mid + 1;
                } else {
                    high = mid;
                }
            }
            last = low - 1;
        }
        return {first, last};
    }
};
