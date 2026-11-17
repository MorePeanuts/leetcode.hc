class Solution {
    public int minSubArrayLen(int target, int[] nums) {
        int left = 0;
        int sum = 0;
        int best = nums.length + 1;
        for (int right = 0; right < nums.length; ++right) {
            sum += nums[right];
            while (sum >= target) {
                int size = right - left + 1;
                if (size < best) {
                    best = size;
                }
                sum -= nums[left++];
            }
        }
        return best > nums.length ? 0 : best;
    }
}
