class Solution {
    static void siftDown(vector<int>& nums, int root, int n) {
        int value = nums[root];
        for (int child = 2 * root + 1; child < n; child = 2 * root + 1) {
            if (child + 1 < n && nums[child] < nums[child + 1]) child++;
            if (nums[child] <= value) break;
            nums[root] = nums[child];
            root = child;
        }
        nums[root] = value;
    }

public:
    vector<int> sortArray(vector<int>& nums) {
        int n = static_cast<int>(nums.size());
        for (int root = n / 2 - 1; root >= 0; root--) siftDown(nums, root, n);

        for (int end = n - 1; end > 0; end--) {
            int value = nums[0];
            nums[0] = nums[end];
            nums[end] = value;
            siftDown(nums, 0, end);
        }
        return nums;
    }
};
