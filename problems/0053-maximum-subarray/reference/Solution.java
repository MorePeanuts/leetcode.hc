class Solution {
    public int maxSubArray(int[] nums) {
        int current = nums[0];
        int best = current;
        for (int i = 1; i < nums.length; i++) {
            current = current > 0 ? current + nums[i] : nums[i];
            if (current > best) best = current;
        }
        return best;
    }
}
