class Solution {
    public int[] maxSlidingWindow(int[] nums, int k) {
        int n = nums.length;
        int[] result = new int[n - k + 1];
        int[] queue = new int[n];
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
}
