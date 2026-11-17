class Solution {
    public int longestOnes(int[] nums, int k) {
        int left = 0;
        int best = 0;
        for (int right = 0; right < nums.length; ++right) {
            k -= 1 - nums[right];
            while (k < 0) {
                k += 1 - nums[left++];
            }
            int size = right - left + 1;
            if (size > best) {
                best = size;
            }
        }
        return best;
    }
}
