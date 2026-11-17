class Solution {
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k) {
        int n = nums.size();
        vector<int> result(n - k + 1), queue(n);
        int head = 0;
        int tail = 0;
        for (int i = 0; i < n; i++) {
            while (tail > head && nums[queue[tail - 1]] <= nums[i]) {
                tail--;
            }
            queue[tail++] = i;
            if (queue[head] <= i - k) {
                head++;
            }
            if (i >= k - 1) {
                result[i - k + 1] = nums[queue[head]];
            }
        }
        return result;
    }
};
