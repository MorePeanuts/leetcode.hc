class Solution {
public:
    int findKthLargest(vector<int> &nums, int k) {
        priority_queue<int, vector<int>, greater<int>> heap(greater<int>(), vector<int>(nums.begin(), nums.begin() + k));
        for (size_t i = k; i < nums.size(); i++) {
            if (nums[i] > heap.top()) {
                heap.pop();
                heap.push(nums[i]);
            }
        }
        return heap.top();
    }
};
